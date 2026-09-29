#include <iostream>
#include <vector>
#include <algorithm>

struct Order{
    int id;
    bool is_buy;
    double price;
    int quantity;
};

class OrderBook{
public:

    std::vector <Order> buy_orders;
    std::vector <Order> sell_orders;

    void addOrder(Order new_Order){
        if (new_Order.is_buy == true){
            buy_orders.push_back(new_Order);
        
            std::sort(buy_orders.begin(), buy_orders.end(), [] (const Order& a, const Order& b){
            return a.price < b.price;});
        }
        else 
        {
            sell_orders.push_back(new_Order);
            std::sort(sell_orders.begin(), sell_orders.end(), [] (const Order& a, const Order& b){
            return a.price > b.price;});
        }
        match();
    }

    void match(){
        while(!buy_orders.empty() && !sell_orders.empty()){
            Order& best_buy = buy_orders.back();
            Order& best_sell = sell_orders.back();

            if(best_buy.price < best_sell.price){
                break;
            }
            
            int traded_quantity = std::min(best_buy.quantity, best_sell.quantity);

            std::cout<< "TRADE EXECUTED: " << traded_quantity <<" shares at $" <<best_sell.price<< " Buyer ID: " << best_buy.id << " | Seller ID: " << best_sell.id<< std::endl;

            best_buy.quantity -= traded_quantity;
            best_sell.quantity -= traded_quantity;

            if (best_buy.quantity == 0) buy_orders.pop_back();
            if (best_sell.quantity == 0) sell_orders.pop_back();
        }

    }
};

int main(){
    OrderBook book;
    std::cout << "============================================== " << std::endl;
    std::cout << "               MARKET OPEN....  " << std::endl;
    std::cout << "============================================== " << std::endl;
    std::cout << std::endl;

    book.addOrder({100,true,150.00,100}); //buyer willing to pay $150 for 100 shares.
    book.addOrder({200,false,153.00,110}); //seller willing to sell 110 shares for $153
    book.addOrder({300,true,140.00,105}); //buyer willing to pay $140 for 105 shares.

    //seller realises buyers arent willing to pay much and lowers her/his price
    book.addOrder({400,false,149.50,95}); 
    std::cout << std::endl;
    std::cout << "ALL POSSIBLE TRADES HAVE BEEN EXECUTED..." <<std::endl;
    return 0;
}
