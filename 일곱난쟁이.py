import sys #sys.exit(0) == return 0; (C++)
CNT =9
arr= [int(input()) for _ in range(CNT)]
arr.sort();
totalSum = sum(arr)
for first in range(CNT):
  for second in range(first+1,CNT):
    if totalSum-(arr[first]+arr[second]) == 100:
      for i in range(CNT):
        if i== first or i == second : 
          continue
        print(arr[i])
      sys.exit(0)  
