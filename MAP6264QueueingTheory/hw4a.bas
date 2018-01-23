100 dim c(50),a(1100)
107 s = 10
108 nstop = 1000000
110 input n
120 for d = 1 to nstop
130 in = 1
132 for i = 2 to n
134 if a(i) < a(in) then in = i
136 next i
138 ia = -0.25*log(rnd(1))
139 ia = ia/n
140 a(in) = a(in)+ia
150 nxt = 1
160 for j = 2 to s
170 if c(j) < c(nxt) then nxt = j
180 next j
190 if c(nxt) <= a(in) then 800
200 k = k+1
210 for j = 1 to s
220 if c(j) < a(in) then c(j) = a(in)
230 next j
240 goto 900
800 x = -2.4*log(rnd(1))
810 sx = sx+x
820 c(nxt) = c(nxt)+x
830 a(in) = c(nxt)
900 next d
910 print k,ab,sx
920 print k/nstop,ab/nstop,sx/(2.4*n)
