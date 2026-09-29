# C++ LIMIT ORDER BOOK

This is a high-performance engine built in C++ to take buy/sell requests, identify overlapping spreads, match both filled and partial orders and remove filled orders. 
I built it to practice how to write low latency code, prevent duplications in memory and manipulate lists efficiently.

![C++20](https://img.shields.io/badge/C++20-blue?logo=c%2B%2B&logoColor=white)

---

## Features 
* **Request Lists** -> It Stores buy/sell requests in lists and sorts them based on who has the lowest selling price or highest buying price.
* **Price Time Priority** -> It Ensures the best and earliest orders are attended to first.
* **Add Orders** -> It Allows the user add a buyer or seller to the market, goes through every request and finds if there is a matching buyer or seller.
* **O(1) Tail Removal** -> It Saves the best buyer and seller at the bottom and when their orders have been filled they are removed from the bottom which follows the O(1) time Complexity.

---

## Data Structures and Algorithms Used
* `std::vector` -> It was used to create separate lists for both buyers and sellers
* `std::sort`-> It was used to arrange the buyers and sellers list according to the best prices
* `std::min` -> It was used to compare the quantities and ensure the right amount of quantities were sold so not to exceed an individuals requested quantity.

---

## How to Build And Run
### Prerequisites
* A C++ compiler supporting c++20 or higher (`g++`)

### 1. Compile The Code
* Run this command in your terminal to turn the `.cpp` file into an executable file named `orderbook`:
``` bash
g++ -std=c++20 main.cpp -o orderbook
```

### 2. Run The Program
* Run that executable file:
``` bash
./orderbook
```

## Sample Output
* When you run the `./orderbook`, the already prepared scenario in the main should print this to your terminal.
```text
============================================== 
               MARKET OPEN....  
============================================== 

TRADE EXECUTED: 95 shares at $149.5 Buyer ID: 100 | Seller ID: 400

ALL POSSIBLE TRADES HAVE BEEN EXECUTED...
```

## Planned Improvements
* **Order Cancellations/Modifications** -> I want to add functions that allow users to cancel orders or modify an order.
* **CLI Interaction** -> I would also add functions that allow users to interact with the terminal and add or manipulate  orders.

  
