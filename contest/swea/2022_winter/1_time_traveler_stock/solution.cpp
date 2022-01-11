#include <vector>
#include <algorithm>

using namespace std;

vector<Order> buyOrderVector;
vector<Order> sellOrderVector;

int buyPrice;
int eraseNumber;

class Order
{
public:
    Order(int,int,int,int);
    int getNumber(void);
    int getPrice(void);
private:
    int number;
    int stock;
    int quantity;
    int price;
};

Order::Order(int mNumber, int mStock, int mQuantity, int mPrice)
 : number(mNumber), stock(mStock), quantity(mQuantity), price(mPrice){}

int Order:: getNumber(void){ return number; }
int Order:: getPrice(void){ return price; }

void init()
{

}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Order buyOrder(mNumber,mStock,mQuantity,mPrice);
    buyPrice = buyOrder.getPrice();

    vector<Order>::iterator it =
    find_if(buyOrderVector.begin(),buyOrderVector.end(),
        [](Order o) { return o.getPrice() <= buyPrice; });



    return 0;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Order sellOrder(mNumber,mStock,mQuantity,mPrice);

    // order 매도 실행

    return 0;
}

void cancel(int mNumber)
{

    bool erasefindFlag = false;
    for (vector<Order>::iterator it = buyOrderVector.begin(); it != buyOrderVector.end(); it++){
        if(it->getNumber() == mNumber){
            eraseFindFlag = true;
            buyOrderVector.erase(i);

        }        
    }

    // eraseNumber = mNumber;

    // buyOrderVector.erase(
    //     remove_if(buyOrderVector.begin(), buyOrderVector.end(),
    //         [](Order o) {return o.getNumber() == eraseNumber;}
    //     )
    // );

    // sellOrderVector.erase(
    //     remove_if(sellOrderVector.begin(), sellOrderVector.end(),
    //         [](Order o) {return o.getNumber() == eraseNumber;}
    //     )
    // );
}

int bestProfit(int mStock)
{
    return 0;
}