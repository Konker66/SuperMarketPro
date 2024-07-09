#include <iostream>
#include <stdlib.h>
using namespace std;

/* Function Declarations */
void user_pager();
void manager_pager();
void show_menu();
void buy_product();

/* Global Variables */
const int MAX_PRODUCTS = 20;
string product[MAX_PRODUCTS] = {"Rice", "Salad", "Meat", "Tomatoes", "Carrots", "Onions", "Tissues", "Bottles", "Glue"};
int prices[MAX_PRODUCTS] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
int menu_size = sizeof(product)/sizeof(product[0]);

int main()
{
    cout << "|================= SuperMarket system =================|" << endl;
    cout << "Press any key to open...";
    getchar();
    int choice_Doing;
    do{
          cout << "Choose the mode from the following : ";
    cout << "\n1 = User";
    cout << "\n2 = Manager";
    cout << "\n3 = Exit...";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        user_pager();
        break;
    case 2:
        manager_pager();
        break;
    case 3:
        cout << "Exiting the program..." << endl;
        break;
    default:
        cout << "Invalid choice, exiting the program..." << endl;
        break;
    }
    }
    while (choice_Doing != 3);
    return 0;
}

void user_pager()
{
    int choice_Doing; // declare the variable
    string user_name;
    
    cout << "|========================|" << endl;
    cout << "Enter your name : ";
    cin >> user_name;
    cout << "|========================|" << endl;
    cout << "|========================|"
         << "Welcome " << user_name << "|========================|" << endl;
    cout << "What you want to do : "
            "\n1 = Show the menu"
            "\n2 = Buy a product"
            "\n3 = Exit..."
            "\n|========================|";
    cin >> choice_Doing;

    switch (choice_Doing)
    {
    case 1:
        show_menu();
        break;
    case 2:
        buy_product();
        break;
    case 3:
        cout << "Returning to main menu..." << endl;
        break;
    default:
        cout << "Invalid choice, returning to main menu..." << endl;
        break;
    }
}

void show_menu()
{
    cout << "|========================|" << endl;
    for (int i = 0; i < menu_size; i++)
    {
        cout << i + 1 << "- " << product[i] << " " << prices[i] << " LE" << endl;
    }
    cout << "|========================|" << endl;
}

void buy_product()
{
    int num_products;
    cout << "Enter the number of products to buy : " << endl;
    cin >> num_products;
    cout << "|========================|" << endl;
    int products_bag[MAX_PRODUCTS] = {0};
    int choice_process;
    do
    {
        cout << "Choose the process : "
                "\n1- Add products to your cart "
                "\n2- Show the receipt "
                "\n3- Return to main menu "
             << endl;
        cin >> choice_process;
        switch (choice_process)
        {
        case 1:
            for (int j = 0; j < num_products; j++)
            {
                cout << "Enter the number of product : " << endl;
                cout << "|========================|" << endl;
                int product_num;
                cin >> product_num;
                if (product_num < 1 || product_num > menu_size)
                {
                    cout << "Invalid product number, please choose again..." << endl;
                    j--;
                }
                else
                {
                    products_bag[j] = product_num;
                }
            }
            cout << "Order Done!" << endl;
            break;
        case 2:
            int sum = 0;
            cout << "|=========== Your Receipt ===========| " << endl;
            for (int k = 0; k < num_products; k++)
            {
                sum += prices[products_bag[k]-1];
                cout << k+1 << "- " << product[products_bag[k]-1] << "  " << prices[products_bag[k]-1] << endl;
            }
            cout << "|========================|" << endl;
            cout << "Total cost is : " << sum << endl;
            // break out of the loop after showing the receipt
            choice_process = 3;
            break;
       
        }
    } while (choice_process != 3);
}

void manager_pager()
{
    string password = "Kenzy123#";
    string input_password;
    cout << "Enter the password to access the system : " << endl;
    cin >> input_password;
    if (input_password != password)
    {
        cout << "Incorrect password, returning to main menu..." << endl;
        return;
    }
    else
    {
        cout << "Access granted, welcome manager!" << endl;
        int choice_process;
        do
        {
            cout << "Choose the process : "
                    "\n1- Add product "
                    "\n2- Remove product "
                    "\n3- Show the inventory "
                    "\n4- Return to main menu "
                 << endl;
            cin >> choice_process;
            switch (choice_process)
            {
            case 1:
                if (menu_size == MAX_PRODUCTS)
                {
                    cout << "The maximum number of products has been reached, cannot add more products..." << endl;
                }
                else
                {
                    string product_name;
                    int price;
                    cout << "Enter the name of the product to add : " << endl;
                    cin >> product_name;
                    cout << "Enter the price of the product to add : " << endl;
                    cin >> price;
                    product[menu_size] = product_name;
                    prices[menu_size] = price;
                    menu_size++;
                    cout << "The product has been added successfully!" << endl;
                }
                break;
            case 2:
                if (menu_size == 0)
                {
                    cout << "The inventory is empty, cannot remove any product..." << endl;
                }
                else
                {
                    int product_num;
                    cout << "Enter the number of the product to remove : " << endl;
                    cin >> product_num;
                    if (product_num < 1 || product_num > menu_size)
                    {
                        cout << "Invalid product number, please choose again..." << endl;
                    }
                    else
                    {
                        for (int i = product_num - 1; i < menu_size - 1; i++)
                        {
                            product[i] = product[i + 1];
                            prices[i] = prices[i + 1];
                        }
                        menu_size--;
                        cout << "The product has been removed successfully!" << endl;
                    }
                }
                break;
            case 3:
                show_menu();
                break;
            case 4:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice, please choose again..." << endl;
                break;
            }
        } while (choice_process != 4);
    }
}

/* NOT READY */