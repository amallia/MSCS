100 dim c(50),a(1100)
105 s = 10
106 nstop = 100000
110 input n
120 for d = 1 to nstop
130 in = 1
132 for i = 2 to n
134 if a(i) < a(in) then in = i
136 next i
138 ia = -(0.25/n)*log(rnd(1))
140 a(in) = a(in)+ia
150 j = 0
160 j = j+1
170 if j = s+1 then k = k+1
180 if j = s+1 then 220
190 if a(in) < c(j) then 160
200 x = -2.4*log(rnd(1))
210 c(j) = a(in)+x
211 a(in) = a(in)+x
220 m = c(1)
230 for i = 2 to s
240 if c(i) < m then m = c(i)
250 next i
260 if m > a(in) then ab = ab+m-a(in)
270 next d
280 print k/nstop,ab/nstop
290 for i = 1 to n
310 next i
