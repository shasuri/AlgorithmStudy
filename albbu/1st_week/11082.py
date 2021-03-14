def bun_simplize(child, parent) :
	bigger = max(child,parent)
	smaller = min(child,parent)

	while (bigger % smaller) != 0:
		remain = bigger % smaller

		bigger = smaller
		smaller = remain

	return smaller

# ------------------------------------------------------

if __name__ == "__main__" :
	
	num = input()

	num = num.split(".")
	integer = num[0]

	if len(num) < 2 :
		print(integer+"/1")

	else :
		floater = num[1]

		floater = floater.split("(")

		unrecur = floater[0]
		unrecur_length = len(unrecur)
		if unrecur == '' :
			unrecur = '0'

		if len(floater) < 2 :
			recur = '0'
		else :
			recur = floater[1][:-1]
			
		recur_length = len(recur)

		# print(integer)
		# print(unrecur)
		# print(recur)

		integer = int(integer)
		unrecur = int(unrecur)
		recur = int(recur)

		origin_upper = 10 ** (unrecur_length + recur_length)
		subtract_upper = 10 ** unrecur_length

		# print(origin_upper)
		# print(subtract_upper)

		origin = (integer * origin_upper) + (unrecur * (10 ** recur_length)) + recur
		subtract = (integer * subtract_upper) + unrecur

		# print(origin)
		# print(subtract)

		bun_child = origin - subtract
		bun_parent = origin_upper - subtract_upper 

		simplizer = bun_simplize(bun_child, bun_parent)
		bun_child = int(bun_child / simplizer)
		bun_parent = int(bun_parent / simplizer)

		print(f"{bun_child}/{bun_parent}")
