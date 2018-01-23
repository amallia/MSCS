100 dim c(50)
110 input s,nstop
120 for d = 1 to nstop
130 ia = -0.25*log(rnd(1))
140 a = a+ia
150 j = 0
160 j = j+1
170 if j = s+1 then k = k+1
180 if j = s+1 then 270
190 if a < c(j) then 160
200 x = -2.4*log(rnd(1))
205 sx = sx+x
210 c(j) = a+x
220 m = c(1)
230 for i = 2 to s
240 if c(i) < m then m = c(i)
250 next i
260 if m > a then ab = ab+m-a
270 next d
280 print k/nstop,ab/a,sx/a
