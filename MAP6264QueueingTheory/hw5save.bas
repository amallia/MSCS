10 dim q(100)
60 svctim = 1
70 arrate = 0.8
80 customers = 1000000
90 input n
100 for i = 1 to customers
110 ia = -(1/arrate)*log(rnd(1))
120 t = t+ia
125 if nq > 0 then 300
130 w = w+x-ia
140 if w < 0 then w = 0
150 if n > 0 AND w > 0 then 400
160 sw = sw+w
170 if w = 0 then x = -svctim*log(rnd(1))
180 sx = sx+x
190 next i
195 print c,sw
200 print "rho=",sx/t,"P(W>0)=",c/customers,"E(W)=",sw/customers
210 end
299 rem have any queued entries been finished
300 nxt = 1
305 for j = 1 to n
310 if q(j) > t then 350
320 if q(j) = 0 then 350
330 nq = nq-1
340 q(j) = 0
350 if q(j) > q(nxt) then nxt = j
360 next j
370 w = q(nxt)-t
375 x = 0
380 goto 130
399 rem wait in a queue
400 if nq >= n then 190
405 c = c+1
410 sw = sw+w
420 j = 0
430 j = j+1
435 if j > n then 180
440 if q(j) <> 0 then 430
450 x = -svctim*log(rnd(1))
460 q(j) = t+w+x
470 nq = nq+1
480 goto 180
