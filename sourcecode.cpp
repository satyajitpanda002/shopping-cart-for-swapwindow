#include"bits/stdc++.h"
using namespace std;

map <string,int>available_items,cart,price;
int amount=0;

void show()                                                                     // function to print the available otems in the shop
{
    cout<<"\n\n the current status of the products in the shop is :\n";
    for(auto i=available_items.begin();i!=available_items.end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
}

void show_price()                                                               // function to print the price of respective items
{
    cout<<"\n\n the prices of the respective products are :\n";
    for(auto i=price.begin();i!=price.end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
}

void show_cart()                                                                   // function to print your cart
{
    if(cart.empty())
        cout<<"your cart is empty now\n\n";
    else
    {
        cout<<"\n\n the current status of the cart is :\n";
        for(auto i=cart.begin();i!=cart.end();i++)
        {
            cout<<i->first<<" "<<i->second<<endl;
        }
        cout<<endl;
    }
}

void add()                                                                          // function to add any item to the cart
{
    string temp;
    int no;
    cout<<"enter the product name and the no of products you want to add to your cart : \n";
    cin>>temp>>no;
    if(no>available_items[temp])
        cout<<"this much number of products is not available, try again\n\n";
    else
    {
        cart[temp]+=no;
        amount+=no*(price[temp]);
        available_items[temp]-=no;
    }
}

void update()                                                                           // function to update any item
{
    string temp;
    int no;
    cout<<"enter the product name and the updated number of that product you want to add to your cart : \n";
    cin>>temp>>no;
    if((no-cart[temp])>available_items[temp])
        cout<<"this much number of products is not available, try again\n\n";
    else
    {
        amount-=cart[temp]*(price[temp]);
        available_items[temp]+=cart[temp];
        cart[temp]=no;
        amount+=no*(price[temp]);
        available_items[temp]-=no;
    }
}

void deletee()                                                                            // function to delete any item from cart
{
    if(cart.empty())
        cout<<"your cart is already empty\n\n"<<endl;
    else
    {
        string temp;
        cout<<"enter the product you want to delete from your cart : \n";
        cin>>temp;
        if(cart.find(temp)!=cart.end())
        {
            amount-=cart[temp]*(price[temp]);
            available_items[temp]+=cart[temp];
            cart.erase(temp);
        }
        else
            cout<<"you have not added this item to your cart \n\n";
    }
}

int main()
{
    available_items.insert({"a",5});
    available_items.insert({"b",15});
    available_items.insert({"c",13});
    available_items.insert({"d",12});
    available_items.insert({"e",7});
    available_items.insert({"f",21});
    available_items.insert({"g",8});

    price["a"]=20;
    price["b"]=10;
    price["c"]=15;
    price["d"]=8;
    price["e"]=14;
    price["f"]=30;
    price["g"]=100;

    cout<<"Welcome to your shopping cart"<<endl;
    int t;
    show();
    show_price();

    do
    {
        cout<<"enter 1 to add a product to the cart\n";
        cout<<"enter 2 to update any product info in the cart\n";
        cout<<"enter 3 to delete any product from the cart\n";
        cout<<"enter 4 to know the total amount of [products you have added in the cart\n";
        cout<<"enter 5 to check the current availability of numbers of products\n";
        cout<<"enter 6 to show your cart\n";
        cout<<"enter 0 to place order and exit\n";
        cin>>t;

        if(t==1)
        {
            add();
        }
        else if(t==2)
        {
            update();
        }
        else if(t==3)
        {
            deletee();
        }
        else if(t==4)
        {
            cout<<"the total amount of products you have added to your cart is : "<<amount<<endl<<endl;
        }
        else if(t==5)
        {
            show();
        }
        else if(t==6)
        {
            show_cart();
        }
        else if(t==0)
        {
            cout<<"thank you for shopping\n";
        }
        else
        {
            cout<<"invalid input\n\n";
        }
    }while(t!=0);
    return 0;
}
