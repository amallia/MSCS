100 dim c(50)
110 input s,nstop
120 for d = 1 to nstop
130 ia = -0.25*log(rnd(1))
140 a = a+ia
150 m = 1
160 for j = 2 to s
170 if c(j) < c(m) then m = j
180 next j
190 if c(m) < a then goto 210
200 ab = ab+c(m)-a
205 k = k+1
210 x = -2.4*log(rnd(1))
220 c(m) = c(m)+x
270 next d
280 print a,ab,k,ab/k
