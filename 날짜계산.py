LAST_YEAR = 15*28*19
e,s,m = map(int,input().split())
cur_e=1
cur_s=1
cur_m=1
for year in range(1,LAST_YEAR+1):
  if cur_e==e and cur_s==s and cur_m==m :
    print(year)
    break
  cur_e+=1
  cur_s+=1
  cur_m+=1
  if cur_e==16 :
    cur_e=1
  if cur_s==29 :
    cur_s=1
  if cur_m==20 :
    cur_m=1
