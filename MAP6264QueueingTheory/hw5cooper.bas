10 rem MAP6264 HW5 Simulation based on Lindley
15 customers = 1000000
20 dim q(100)
95 input n
100 for i = 1 to customers
110 ia = -1*(1/0.8)*log(rnd(1))
120 t = t+ia
130 w = w+x-ia
140 if w < 0 then w = 0
150 if w > 0 then 205
160 sw = sw+w
170 x = -log(rnd(1))
180 sx = sx+x
190 next i
200 print sx/t,c/customers,sw/(customers-c)
202 end
205 j = 0
210 j = j+1
215 if j > n then c = c+1
218 if j > n then x = 0
220 if j > n then 190
230 if q(j) > t then 210
240 q(j) = t+w
250 goto 160
