10 dim q(1000)
60 svctim = 1
70 arrate = 0.8
80 customers = 10000000
90 input n
100 for i = 1 to customers
110 ia = -(1/arrate)*log(rnd(1))
120 t = t+ia
125 w = w-ia
126 if w < 0 then w = 0
130 if nq = 0 then 300
139 rem have any queued entries been finished
150 for j = 1 to n
160 if q(j) > t then 200
170 if q(j) = 0 then 200
180 nq = nq-1
190 q(j) = 0
200 next j
300 rem process incoming call
310 x = -svctim*log(rnd(1))
320 if w = 0 then 380
330 rem queue it if possible
340 j = 0
345 j = j+1
350 if q(j) <> 0 then 345
353 if j > n then 400
355 sw = sw+w
360 q(j) = t+w+x
365 k = k+1
370 nq = nq+1
380 c = c+1
385 w = w+x
390 sx = sx+x
400 next i
410 print c,k,sx,sw, nq, w
420 print "rho=",(sx-w)/t,"PI(n+1)=",(customers-c-nq)/customers,"P(W>0)=",k/customers,"W(N)=",((sw-w)/svctim)/c,"E(W)=",(sw/svctim)/(c*arrate)
430 end
