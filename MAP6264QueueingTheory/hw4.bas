100 dim c(50),a(1100)
107 s = 10
108 nstop = 1000000
110 input n
120 for d = 1 to nstop
130 in = 1
132 for i = 2 to n
134 if a(i) < a(in) then in = i
136 next i
137 ahat = 9.6/(n-9.6)
138 gamma = ahat/2.4
139 tt = (-1/gamma)*log(rnd(1))
140 clock = a(in)
145 a(in) = a(in)+tt
150 j = 0
160 j = j+1
170 if j = s+1 then k = k+1
180 if j = s+1 then 270
190 if clock < c(j) then 160
200 x = -2.4*log(rnd(1))
205 sx = sx+x
210 c(j) = clock+x
215 a(in) = a(in)+x
220 m = c(1)
230 for i = 2 to s
240 if c(i) < m then m = c(i)
250 next i
260 if m > clock then ab = ab+m-clock
270 next d
300 print "P10[",n,"]=",ab/clock," Pi(10)[",n,"]=",k/nstop," rho[",n,"]=",sx/clock/s
