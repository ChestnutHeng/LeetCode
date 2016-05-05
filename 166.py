def fractionToDecimal(num, den):
	mapo = {}
	rev_mapo = {}
	n2=[]
	ans = ""
	n1 = num//den
	if n1 < 0 or num < 0 or den < 0:
	    num = abs(num)
	    den = abs(den)
	    if n1 < 0:
	        ans = "-"
	    n1 = num//den
	    
	num = (num % den)*10
	left = 0
	ans += str(n1)
	while(True):
		if(num in rev_mapo):
			left = rev_mapo[num]
			break
		else:
			mapo[left] = num
			rev_mapo[num] = left
			left += 1
			#update num
			up = num // den
			num = (num - den * up)*10
			n2.append(up)
			if num == 0:
				left = -1
				break
			
			
	if left == -1:
		if len(n2) > 1 or n2[0] != 0:
			ans += "."
			for i in range(0,len(n2)):
				ans += str(n2[i])
		return ans
	ans += "."
	for i in range(0,len(n2)):
		if i == left:
			ans += "("
		ans += str(n2[i])
	ans += ")"
	return ans
    
    
x = int(input())
y = int(input())
print(fractionToDecimal(x,y))
