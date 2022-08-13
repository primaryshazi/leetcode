#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<int, std::string> phoneButton = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
};

void letterCombinationsCore(const std::string &digits, size_t index, std::string &combine, std::vector<std::string> &result)
{
    if (index == digits.length())
    {
        result.emplace_back(combine);
        return;
    }

    char ch = digits[index];        // 数字
    auto &str = phoneButton.at(ch); // 数字所对应的字符串

    // 递归拼接字符串
    for (auto ch : str)
    {
        combine.push_back(ch);
        letterCombinationsCore(digits, index + 1, combine, result);
        combine.pop_back();
    }
}

std::vector<std::string> letterCombinations(const std::string &digits)
{
    if (digits.empty())
    {
        return {};
    }
    std::string combine;
    std::vector<std::string> result;
    letterCombinationsCore(digits, 0, combine, result);

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    /**
     * => { aa, ab, ac, ba, bb, bc, ca, cb, cc }
     * => { ad, ae, af, bd, be, bf, cd, ce, cf }
     * => { ag, ah, ai, bg, bh, bi, cg, ch, ci }
     * => { aj, ak, al, bj, bk, bl, cj, ck, cl }
     * => { am, an, ao, bm, bn, bo, cm, cn, co }
     * => { ap, aq, ar, as, bp, bq, br, bs, cp, cq, cr, cs }
     * => { at, au, av, bt, bu, bv, ct, cu, cv }
     * => { aw, ax, ay, az, bw, bx, by, bz, cw, cx, cy, cz }
     * => { da, db, dc, ea, eb, ec, fa, fb, fc }
     * => { dd, de, df, ed, ee, ef, fd, fe, ff }
     * => { dg, dh, di, eg, eh, ei, fg, fh, fi }
     * => { dj, dk, dl, ej, ek, el, fj, fk, fl }
     * => { dm, dn, do, em, en, eo, fm, fn, fo }
     * => { dp, dq, dr, ds, ep, eq, er, es, fp, fq, fr, fs }
     * => { dt, du, dv, et, eu, ev, ft, fu, fv }
     * => { dw, dx, dy, dz, ew, ex, ey, ez, fw, fx, fy, fz }
     * => { ga, gb, gc, ha, hb, hc, ia, ib, ic }
     * => { gd, ge, gf, hd, he, hf, id, ie, if }
     * => { gg, gh, gi, hg, hh, hi, ig, ih, ii }
     * => { gj, gk, gl, hj, hk, hl, ij, ik, il }
     * => { gm, gn, go, hm, hn, ho, im, in, io }
     * => { gp, gq, gr, gs, hp, hq, hr, hs, ip, iq, ir, is }
     * => { gt, gu, gv, ht, hu, hv, it, iu, iv }
     * => { gw, gx, gy, gz, hw, hx, hy, hz, iw, ix, iy, iz }
     * => { ja, jb, jc, ka, kb, kc, la, lb, lc }
     * => { jd, je, jf, kd, ke, kf, ld, le, lf }
     * => { jg, jh, ji, kg, kh, ki, lg, lh, li }
     * => { jj, jk, jl, kj, kk, kl, lj, lk, ll }
     * => { jm, jn, jo, km, kn, ko, lm, ln, lo }
     * => { jp, jq, jr, js, kp, kq, kr, ks, lp, lq, lr, ls }
     * => { jt, ju, jv, kt, ku, kv, lt, lu, lv }
     * => { jw, jx, jy, jz, kw, kx, ky, kz, lw, lx, ly, lz }
     * => { ma, mb, mc, na, nb, nc, oa, ob, oc }
     * => { md, me, mf, nd, ne, nf, od, oe, of }
     * => { mg, mh, mi, ng, nh, ni, og, oh, oi }
     * => { mj, mk, ml, nj, nk, nl, oj, ok, ol }
     * => { mm, mn, mo, nm, nn, no, om, on, oo }
     * => { mp, mq, mr, ms, np, nq, nr, ns, op, oq, or, os }
     * => { mt, mu, mv, nt, nu, nv, ot, ou, ov }
     * => { mw, mx, my, mz, nw, nx, ny, nz, ow, ox, oy, oz }
     * => { pa, pb, pc, qa, qb, qc, ra, rb, rc, sa, sb, sc }
     * => { pd, pe, pf, qd, qe, qf, rd, re, rf, sd, se, sf }
     * => { pg, ph, pi, qg, qh, qi, rg, rh, ri, sg, sh, si }
     * => { pj, pk, pl, qj, qk, ql, rj, rk, rl, sj, sk, sl }
     * => { pm, pn, po, qm, qn, qo, rm, rn, ro, sm, sn, so }
     * => { pp, pq, pr, ps, qp, qq, qr, qs, rp, rq, rr, rs, sp, sq, sr, ss }
     * => { pt, pu, pv, qt, qu, qv, rt, ru, rv, st, su, sv }
     * => { pw, px, py, pz, qw, qx, qy, qz, rw, rx, ry, rz, sw, sx, sy, sz }
     * => { ta, tb, tc, ua, ub, uc, va, vb, vc }
     * => { td, te, tf, ud, ue, uf, vd, ve, vf }
     * => { tg, th, ti, ug, uh, ui, vg, vh, vi }
     * => { tj, tk, tl, uj, uk, ul, vj, vk, vl }
     * => { tm, tn, to, um, un, uo, vm, vn, vo }
     * => { tp, tq, tr, ts, up, uq, ur, us, vp, vq, vr, vs }
     * => { tt, tu, tv, ut, uu, uv, vt, vu, vv }
     * => { tw, tx, ty, tz, uw, ux, uy, uz, vw, vx, vy, vz }
     * => { wa, wb, wc, xa, xb, xc, ya, yb, yc, za, zb, zc }
     * => { wd, we, wf, xd, xe, xf, yd, ye, yf, zd, ze, zf }
     * => { wg, wh, wi, xg, xh, xi, yg, yh, yi, zg, zh, zi }
     * => { wj, wk, wl, xj, xk, xl, yj, yk, yl, zj, zk, zl }
     * => { wm, wn, wo, xm, xn, xo, ym, yn, yo, zm, zn, zo }
     * => { wp, wq, wr, ws, xp, xq, xr, xs, yp, yq, yr, ys, zp, zq, zr, zs }
     * => { wt, wu, wv, xt, xu, xv, yt, yu, yv, zt, zu, zv }
     * => { ww, wx, wy, wz, xw, xx, xy, xz, yw, yx, yy, yz, zw, zx, zy, zz }
     */
    for (int i = 2; i <= 9; i++)
    {
        for (int j = 2; j <= 9; j++)
        {
            std::cout << letterCombinations(std::to_string(i) + std::to_string(j)) << std::endl;
        }
    }

    return 0;
}
