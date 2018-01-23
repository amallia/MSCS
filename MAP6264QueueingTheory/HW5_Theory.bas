100 dim wl(10010),pj(10010),pij(10010),rho(10010)
101 limit = 5000
102 load = 0.8
103 pj(0) = 0
104 for n = 1 to limit+10
110 x(0) = 1
111 norm = 1
112 for j = 1 to n
120 x(j) = load *x(j-1)
121 norm = norm+x(j)
122 next j
130 for j = 1 to n
131 x(j) = x(j)/norm
132 next j
140 pj(n-1) = x(n)
141 pij(n) = x(n)
142 rho(n-1) = load *(1-pj(n-1))
143 wl(n) = 0
144 for j = 1 to n
150 wl(n) = wl(n)+(x(j)*(j-1))
151 next j
160 wl(n) = wl(n)/rho(n-1)
170 next n
180 for n = 0 to 32
181 print "rh(",n,")=",rho(n)
182 print "Pi(",n+1,")=",pij(n+1)
183 print "Wl(",n,")=",wl(n)
184 next n
