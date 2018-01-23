10 count = 1000000
90 for ewe = 0 to 5 step 0.5
91 sx = 0 : si = 0 : sr = 0
92 c = 0
100 for j = 1 to count
110 s = 0
120 t = -400*log(rnd(1))
130 y = 1
133 if (rnd(1) <= 0.1) then y = 11
135 x = y+ewe
140 c = c+1
150 sx = sx+x
160 s = s+x
170 if s < t then 130
180 r = s-t
185 i = x
190 sr = sr+r
195 si = si+i
200 next j
210 print sx/c,si/count,sr/count
220 next ewe
