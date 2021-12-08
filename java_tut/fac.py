from icecream import ic

data = [
    {
        "name": "cash",
        "amount": 189000
    },
    {
        "name": "account recienvable",
        "amount": 0
    },
    {
        "name": "computer supplies",
        "amount": 47000
    },
    {
        "name": "computer equipment",
        "amount": 100000
    },
    {
        "name": "accounts payable",
        "amount": 0
    },
    {
        "name": "loans payable",
        "amount": 100000
    },
    {
        "name": "own capital",
        "amount": 300000
    },
    {
        "name": "service income",
        "amount": 5000
    },
    {
        "name": "dics recd",
        "amount": 4000
    },
    {
        "name": "withdrawal for personal",
        "amount": 25000
    },
    {
        "name": "salary",
        "amount": 20000
    },
    {
        "name": "rent paid",
        "amount": 5000
    },
    {
        "name": "tax pay",
        "amount": 20000
    }
]

for i in range(len(data)):
    data[i]["id"] = i + 1

data.sort(key=lambda x: x["amount"])

def get_amount(subdata):
    return sum(x["amount"] for x in subdata)

def divide_debit_credit(data):
    half = 0
    #find amount median
    amount_mean = get_amount(data) // len(data)
    while half < len(data) and data[half]["amount"] < amount_mean:
        half += 1

    debit, credit = data[:half], data[half:]
    debit_sum = get_amount(debit)
    credit_sum = get_amount(credit)
    max_iter = 0

    while (max_iter <= 5 or 1) and debit_sum != credit_sum:
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
                temp_credit += debit[-i]["amount"]
                temp_debit -= debit[-i]["amount"]
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
        debit_sum = get_amount(debit)
        credit_sum = get_amount(credit)
        print(f'debit: {[i["amount"] for i in debit]}\n credit: {[i["amount"] for i in credit]}')
        print(debit_sum, credit_sum)


    final_sum = sum(x["amount"] for x in debit)
    return final_sum, debit, credit

fsum, debit, credit = divide_debit_credit(data)
# print(debit)
# print(credit)
print(fsum)