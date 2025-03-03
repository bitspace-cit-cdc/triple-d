# Problem: Invalid Transactions

A transaction is possibly invalid if:

1. The amount exceeds $1000, or;
2. It occurs within (and including) 60 minutes of another transaction with the same name in a different city, or;
3. The user making the transaction is below a certain age (`min_age`), in which case all transactions by that user are invalid.

You are given an array of strings `transactions` where each element represents a transaction in the format `"name,time,amount,city,age"`, where:
- `name` is the name of the user,
- `time` is the transaction's time in minutes (from the start of the day),
- `amount` is the transaction amount in dollars,
- `city` is the city where the transaction took place,
- `age` is the age of the user making the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

### Input:
- `transactions`: An array of strings, where each string is in the format `"name,time,amount,city,age"`.
- `max_transactions_per_city`: An integer specifying the maximum number of transactions allowed in the same city within 60 minutes (default value is `2`).
- `min_age`: An integer specifying the minimum valid age for a user (default value is `18`).

### Output:
- A list of strings representing the invalid transactions.

### Example 1:
```
transactions = ["alice,20,800,mtv,17", "alice,50,100,beijing,22", "alice,70,200,mtv,25", "bob,50,1200,mtv,30", "alice,80,500,mtv,17", "alice,100,200,mtv,22", "alice,110,500,mtv,25"]
max_transactions_per_city = 2
min_age = 18
```


**Constrains:**
- `transactions.length <= 1000`
- Each `transactions[i]` takes the form `"{name},{time},{amount},{city}"`
- Each `{name}` and `{city}` consist of lowercase English letters, and have lengths between `1` and `10`.
- Each `{time}` consist of digits, and represent an integer between `0` and `1000`.
- Each `{amount}` consist of digits, and represent an integer between `0` and `2000`.