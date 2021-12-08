from icecream import ic

# data = [100, 50,300,445,55,250,200,250,750]
data = [189000, 47000, 100000, 300000, 5000, 4000, 25000, 20000, 5000, 20000]

data.sort()

def divide_equal_half(data):
    half = len(data) // 2
    debit, credit = data[:half], data[half:]
    debit_sum = sum(debit)
    credit_sum = sum(credit)
    max_iter = 0

    while debit_sum != credit_sum:
        max_iter += 1
        temp_debit = debit_sum
        temp_credit = credit_sum
        original_diff = temp_diff = abs(debit_sum - credit_sum)
        if debit_sum > credit_sum:
            made_changes = False
            i = 1
            while i < len(debit) and not made_changes:
                i += 1
                # ic(i)
                temp_debit = debit_sum
                temp_credit = credit_sum
                temp_credit += debit[-i]
                temp_debit -= debit[-i]
                temp_diff = abs(temp_debit - temp_credit)
                if temp_diff < original_diff:
                    # positive, make changes
                    td = debit[-i]
                    del debit[-i]
                    credit.append(td)
                    made_changes = True
            if not made_changes:
                # positive, make changes
                td = debit[-1]
                del debit[-1]
                credit.append(td)

            print('\nfrom debit')
        else:
            print('\nfrom credit')
            td = credit[0]
            credit.remove(td)
            debit.append(td)
        debit_sum = sum(debit)
        credit_sum = sum(credit)
        print(f'debit: {debit}\n credit: {credit}')
        print(debit_sum, credit_sum)


    final_sum = sum(debit)
    return final_sum, debit, credit

fsum, debit, credit = divide_equal_half(data)
# print(debit)
# print(credit)
print(fsum)