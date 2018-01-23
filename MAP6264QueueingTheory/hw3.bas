100 dim c(50),wt(10)
110 input s,nstop
120 for d = 1 to nstop
130 ia = -(1/0.8)*log(rnd(1))
140 a = a+ia
150 m = 1
160 for j = 2 to s
170 if c(j) < c(m) then m = j
180 next j
190 if c(m) < a then goto 210
195 wx = c(m)-a
197 for i = 0 to 9
198 if (wx > i) then wt(i+1) = wt(i+1)+1
199 next i
200 ab = ab+c(m)-a
205 k = k+1
210 x = -1*log(rnd(1))
212 sx = sx+x
215 if c(m) < a then c(m) = a
220 c(m) = c(m)+x
270 next d
280 print k/nsstop,ab/k,a/sx
281 print nstop/a,sx/(a*10)
290 for i = 1 to 10
300 print "P(w>",i-1,")=",wt(i)/nstop
310 next i
