60 input n
70 arr = 0.8
80 svct = 1
90 dim q(100)
100 customers = 1000000
110 for i = 1 to customers
120 ia = -(1/arr)*log(rnd(1))
130 t = t+ia
140 w = w+x-ia
150 if w < 0 then w = 0
160 if w > 0 then c = c+1
170 x = -svct*log(rnd(1))
180 sx = sx+x
190 sw = sw+w
200 next i
210 print sx,c,sw
220 print sx/t,c/customers,sw/customers
