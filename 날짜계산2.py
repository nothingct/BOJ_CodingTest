MOD_E=15
MOD_S=28
MOD_M=19
LAST_YEAR=MOD_E*MOD_S*MOD_M
e,s,m = map(int,input().split())
e-=1
s-=1
m-=1
for year in range(LAST_YEAR):
  if year % MOD_E==e and year%MOD_S==s and year%MOD_M==m:
    print(year+1)
    break