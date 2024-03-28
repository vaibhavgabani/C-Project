#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Define a structure representing a product
struct product
{
    int p_id;
    char p_name[20];
    int p_category;
    char p_manufacturer[20];
    int p_quantity;
    int p_price;
    int p_supplierid;
};
// Define a structure representing a supplier
struct supplier
{
    int s_id;
    char s_name[20];
    long long int s_contact;
    char s_address[100];
    char s_city[50];
};
struct user
{
    char u_name[20];
    long long int u_contact;
    char u_password[20];
};
// all UDF
void print_menu(char[]);
void print_loginmenu();
void input_product();       // Taking input for products
void input_supplier();      // input supplier data
void print_product();       // print all data from products
void print_supplier();      // print all data from products
int cnt_product();          // return total record inside product.dat
int cnt_supplier();         // return total record inside supplier.dat
int check_product_id(int);  // check id from product.dat return 1 if found
int check_supplier_id(int); // check id from supplier.dat return 1 if found
int check_supplier_contact(long long int);
int check_supplier_id_from_product(int );
int check_p_category(int);             // check category in 3 part 1 : Electronics || 2 : Mobile || 3 : Personal Computers[PC]
int check_p_category_and_price(int);   // return 1 if number is wrong
int check_s_contact(long long int);    // return 1 of number is wrong
int check_product();                   // return 1 if found record
void advanced_p_name_search();         // search name form product
void advanced_p_manufacturer_search(); // search manufacturer from product
void p_quantity_search();              // search quantity form product base on min max value
void p_price_search();                 // search price form product base on min max value
void advanced_s_name_search();         // search supplier from name
void advanced_s_city_search();         // search supplier from city
void delete_p_row_product();           // remove row from product struct
void delete_p_row_supplier();          // remove the supplier id wia product id
void delete_s_id_supplier();           // delete supplier id supplier
void update_p_quantity();              // update quantity of the product
void update_p_price();                 // update price of the product
void update_p_name();                  // update product name
void update_s_name();                  // update supplier name
void short_p_name_asending();          // shorting by product name
void short_p_name_desending();         // shorting by product name
void short_s_name_asending();          // shorting by supplier name
void short_s_name_desending();         // shorting by supplier name
void short_P_price_asending();         // shorting by product price
void short_P_price_desending();        // shorting by product price
void short_p_quntity_asending();       // shorting by product quntity
void short_p_quntity_desending();      // shorting by product quntity
int check_user_contact(long long int);
void update_price_product();
void signup();
void print_user();
int main()
{
    int choice_login, flag = 0;
    char username[20];
    do
    {
        print_loginmenu();
        printf("Enter Your Choice Here : ");
        scanf("%d", &choice_login);

        if (choice_login == 1)
        {
            FILE *fptr;
            struct user s;
            int login_flag = 0;
            long long int contect_number;
            char password[20];

            fptr = fopen("user.dat", "rb");
            if (fptr == NULL)
            {
                printf("file not found\n");
                break;
            }
            printf("Enter Your Contect Number: ");
            scanf(" %lld", &contect_number);

            printf("Enter Your Password: ");
            scanf(" %s", password);
            rewind(fptr);

            while (fread(&s, sizeof(struct user), 1, fptr))
            {
                if (s.u_contact == contect_number && strcmp(s.u_password, password) == 0)
                {
                    strcpy(username, s.u_name);
                    login_flag = 1;
                    break;
                }
            }
            fclose(fptr);
            if (login_flag == 0)
            {
                printf("\nYou Are Not Registered!!!\n");
            }
            else
            {
                // system("cls");
                printf("\n\n\n Successfully Login...\n");
                flag = 1;
                printf("\n\tWelcome %s\n", username);
            }

            if (flag == 1)
            {
                break;
            }
        }
        else if (choice_login == 2)
        {
            signup();
        }
        else if (choice_login == 3)
        {
            break;
        }
        else
        {
            printf("Enter Valid Choice\n");
        }
        if (flag == 1)
        {
            break;
        }
    } while (choice_login != 3);

    if (flag == 1)
    {
        int choice_menu;
        do
        {
            print_menu(username);
            printf("Enter Your Choice Here : ");
            scanf("%d", &choice_menu);

            switch (choice_menu)
            {
            case 1:
                printf("\n\n\n");
                input_product(); // Taking input for products
                // printf("\n\n\n");
                break;

            case 2:
                printf("\n\n\n");
                input_supplier(); // input supplier data
                // printf("\n\n\n");
                break;

            case 3:
                printf("\n\n\n");
                print_product(); // print all data from products
                // printf("\n\n\n");
                break;

            case 4:
                printf("\n\n\n");
                print_supplier(); // print all data from products
                // printf("\n\n\n");
                break;

            case 5:
                printf("\n\n\n");
                advanced_p_name_search();
                // printf("\n\n\n");
                break;

            case 6:
                printf("\n\n\n");
                advanced_p_manufacturer_search();
                printf("\n\n\n");
                break;

            case 7:
                printf("\n\n\n");
                p_quantity_search(); // search quantity form product base on min max value
                printf("\n\n\n");
                break;

            case 8:
                printf("\n\n\n");
                p_price_search(); // search price form product base on min max value
                printf("\n\n\n");
                break;

            case 9:
                printf("\n\n\n");
                advanced_s_name_search(); // search supplier from name
                printf("\n\n\n");
                break;

            case 10:
                printf("\n\n\n");
                advanced_s_city_search(); // search supplier from city
                printf("\n\n\n");
                break;

            case 11:
                printf("\n\n\n");
                short_p_name_asending(); // shorting by product name
                printf("\n\n\n");
                break;

            case 12:
                printf("\n\n\n");
                short_P_price_asending(); // shorting by product price
                printf("\n\n\n");
                break;

            case 13:
                printf("\n\n\n");
                short_p_quntity_asending(); // shorting by product quntity
                printf("\n\n\n");
                break;

            case 14:
                printf("\n\n\n");
                short_p_name_desending(); // shorting by product name
                printf("\n\n\n");
                break;

            case 15:
                printf("\n\n\n");
                short_P_price_desending(); // shorting by product price
                printf("\n\n\n");
                break;

            case 16:
                printf("\n\n\n");
                short_p_quntity_desending(); // shorting by product quntity
                printf("\n\n\n");
                break;

            case 17:
                printf("\n\n\n");
                update_p_name(); // update product name
                printf("\n\n\n");
                break;

            case 18:
                printf("\n\n\n");
                update_p_quantity(); // update quantity of the product
                printf("\n\n\n");
                break;

            case 19:
                printf("\n\n\n");
                update_p_price(); // update price of the product
                printf("\n\n\n");
                break;

            case 20:
                printf("\n\n\n");
                update_s_name(); // update supplier name
                printf("\n\n\n");
                break;

            case 21:
                printf("\n\n\n");
                delete_p_row_product(); // remove row from product struct
                printf("\n\n\n");
                break;

            case 22:
                printf("\n\n\n");
                delete_p_row_supplier(); // remove the supplier id wia product id
                printf("\n\n\n");
                break;

            case 23:
                printf("\n\n\n");
                delete_s_id_supplier(); // delete supplier id supplier
                printf("\n\n\n");
                break;

            case 24:
                printf("\n\n\n");
                break;
            default:
                printf("Enter Valid Choice...\n");
            }

        } while (choice_menu != 24);
    }
    printf("Thank You :)\n");
    // print_user();
    // print_supplier();
    return 0;
}
void print_loginmenu()
{ // login menu
    printf("+==============================================+\n");
    printf("|                MENU OPTIONS                  |\n");
    printf("+==============================================+\n");
    printf("|   1 = LOG IN                                 |\n");
    printf("|   2 = SIGN UP                                |\n");
    printf("|   3 = EXIT                                   |\n");
    printf("+==============================================+\n");
    return;
}
void print_menu(char str[])
{
    printf("\n+=========================================================================================+\n");
    printf("|                              INVENTORY MANAGEMENT SYSTEM                                |\n");
    printf("|                                                                                         |\n");
    printf("| USERNAME : %-20s                                       DATE:%-12s |\n", str, __DATE__);
    printf("|=========================================================================================|\n");
    printf("| => INPUT                                             => DISPLAY                         |\n");
    printf("|    1. PRODUCT ENTRY                                    3. PRODUCT CATALOG               |\n");
    printf("|    2. SUPPLIER ENTRY                                   4. SUPPLIER DIRECTORY            |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("| => SEARCH                                                                               |\n");
    printf("|    I. FOR PRODUCT :                                 II.FOR SUPPLIER :                   |\n");
    printf("|       5. PRODUCT NAME                                  9. SUPPLIER NAME                 |\n");
    printf("|       6. MANUFACTURER NAME                             10.SUPPLIER CITY                 |\n");
    printf("|       7. QUANTITY                                                                       |\n");
    printf("|       8. PRICE                                                                          |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("| => SORT                                                                                 |\n");
    printf("|    I.ASCENDING :                                   II.DESCENDING :                      |\n");
    printf("|      11. PRODUCT NAME                                 14. PRODUCT NAME                  |\n");
    printf("|      12. PRODUCT PRICE                                15. PRODUCT PRICE                 |\n");
    printf("|      13. PRODUCT QUANTITY                             16. PRODUCT QUANTITY              |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("| => UPDATE                                             => DELETE                         |\n");
    printf("|   17. PRODUCT NAME                                    21. PRODUCT BASED ON PRODUCT ID   |\n");
    printf("|   18. PRODUCT QUANTITY                                22. PRODUCT BASED ON SUPPLIER ID  |\n");
    printf("|   19. PRODUCT PRICE                                   23. SUPPLIER BASED ON SUPPLIER ID |\n");
    printf("|   20. SUPPLIER NAME                                                                     |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("| => 24.EXIT                                                                              |\n");
    printf("+_________________________________________________________________________________________+\n");
    return;
}
void signup()
{
    FILE *fptr;
    struct user s;

    fptr = fopen("user.dat", "a");
    if (fptr == NULL)
    {
        printf("::::::::::::::::::::::::::::::::");
        printf(": No Users Found In The System :\n");
        printf("::::::::::::::::::::::::::::::::");
        return;
    }
    // Taking input for suppliers
    int id_flag1 = 0;

    // taking input of name
    printf("Enter Your Name: ");
    scanf(" %[^\n]", s.u_name);

    int id_flag2 = 0;
    // taking input of contact number
    do
    {
    up:
        printf("Enter Your Contact: ");
        scanf(" %lld", &s.u_contact);

        if (check_s_contact(s.u_contact) == 1)
        {
            printf("\n");
            printf("::::::::::::::::::::::::::::::::::::::\n");
            printf(": Contact number should be 10 digits :\n");
            printf("::::::::::::::::::::::::::::::::::::::\n\n");
            goto up;
        }
        // check from file
        id_flag2 = check_user_contact(s.u_contact);
        if (id_flag2 == 1)
        {
            printf("\n");
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(": Contact Number Already Exists ! Please Choose a Different One :\n");
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        }
    } while (id_flag2 == 1);

    // taking input of address
    printf("Enter Your Password: ");
    scanf(" %[^\n]", s.u_password);

    fwrite(&s, sizeof(struct user), 1, fptr);

    fclose(fptr);
    printf("You have successfully signed up.\n");
    return;
}
void input_product()
{ // Taking input for products
    if (cnt_supplier() > 0)
    {
        printf("Enter Product Details : \n");
        FILE *fptr;
        struct product s;
        fptr = fopen("product.dat", "a");
        if (fptr == NULL)
        {
            printf(":::::::::::::::::::::::::::::");
            printf(":product.dat file not found :\n");
            printf(":::::::::::::::::::::::::::::");
            return;
        }
        // input of id
        int id_flag = 0;
        do
        {
        id_up:
            printf("Enter the Product ID: ");
            scanf("%d", &s.p_id);
            if (s.p_id < 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
                goto id_up;
            }
            // check from file
            id_flag = check_product_id(s.p_id);
            if (id_flag == 1)
            {
                printf("\n");
                printf("::::::::::::::::::::::::::::::::::::::::\n");
                printf(": Entered ID is Already Exists In File :\n");
                printf("::::::::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (id_flag == 1);

        // input of name
        printf("Enter the Product Name: ");
        scanf(" %[^\n]", s.p_name);

        // taking input of catogery
        do
        {
            int flag = 0;
            printf("Enter Category:- \n");
            printf("Press 1 for :Electronics\n");
            printf("Press 2 for :Mobile\n");
            printf("Press 3 for :PC(Personal computers)\n");
            printf("Enter Here :");
            scanf(" %d", &s.p_category);
            flag = check_p_category(s.p_category);
            if (flag == 1)
            {
                printf("\n");
                printf("::::::::::::::::::::::::\n");
                printf(": Enter Valid Category :\n");
                printf("::::::::::::::::::::::::\n\n");
            }
            else
            {
                break;
            }
        } while (1);

        // taking input Manufacturer
        printf("Enter The Product Manufacturer Name : ");
        scanf(" %[^\n]", s.p_manufacturer);

        // taking input quantity
        do
        {
            int flag = 0;
            printf("Enter the Product Quantity: ");
            scanf("%d", &s.p_quantity);
            flag = check_p_category_and_price(s.p_quantity);
            if (flag == 1)
            {
                printf("\n");
                printf("::::::::::::::::::::::::\n");
                printf(": Enter Valid Quantity :\n");
                printf("::::::::::::::::::::::::\n\n");
            }
            else
            {
                break;
            }

        } while (1);

        // taking input prise
        do
        {
            int flag = 0;
            printf("Enter the Product Price: ");
            scanf("%d", &s.p_price);
            flag = check_p_category_and_price(s.p_price);
            if (flag == 1)
            {
                printf("\n");
                printf("::::::::::::::::::::::::\n");
                printf(": Enter Valid Quantity :\n");
                printf("::::::::::::::::::::::::\n\n");
            }
            else
            {
                break;
            }
        } while (1);

        // taking input suppiler id
        do
        {
            int flag = 0;
            printf("Enter the Product Supplier ID: ");
            scanf("%d", &s.p_supplierid);
            flag = check_supplier_id(s.p_supplierid);
            if (flag != 1)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::::::::::::::::\n");
                printf(": Entered Suppiliers ID is not exists :\n");
                printf(":::::::::::::::::::::::::::::::::::::::\n\n");
            }
            else
            {
                break;
            }
        } while (1);
        fwrite(&s, sizeof(struct product), 1, fptr);
        fclose(fptr);
        printf("\nQuery OK, %d rows affected.\n", 1);
    }
    else
    {
        printf("Please Provide The Details Of The Supplier:");
    }
    return;
}
void input_supplier()
{ // Function to input supplier data
    printf("Enter Supplier Details : \n");
    FILE *fptr;
    struct supplier s;
    fptr = fopen("supplier.dat", "a");
    if (fptr == NULL)
    {
        printf(":::::::::::::::::::::::::::::::");
        printf(": supplier.dat file not found :\n");
        printf(":::::::::::::::::::::::::::::::");
        return;
    }
    // Taking input for suppliers
    int id_flag1 = 0; // Declare id_flag once here
    // input of id
    do
    {
    id_up:
        printf("Enter the Supplier ID: ");
        scanf("%d", &s.s_id);
        if (s.s_id < 0)
        {
            printf("\n");
            printf(":::::::::::::::::::::::::\n");
            printf(": Enter Positive Number :\n");
            printf(":::::::::::::::::::::::::\n\n");
            goto id_up;
        }

        // check from file
        id_flag1 = check_supplier_id(s.s_id);
        if (id_flag1 == 1)
        {
            printf("\n");
            printf(":::::::::::::::::::::::::::::::::::::\n");
            printf(":Enter ID is Already Exists In File :\n");
            printf(":::::::::::::::::::::::::::::::::::::\n\n");
        }

    } while (id_flag1 == 1);

    // taking input of name
    printf("Enter the Supplier Name: ");
    scanf(" %[^\n]", s.s_name);

    int id_flag2 = 0;
    // taking input of contact number
    do
    {
    up:
        printf("Enter the Supplier Contact: ");
        scanf(" %lld", &s.s_contact);

        if (check_s_contact(s.s_contact) == 1)
        {
            printf("\n");
            printf("::::::::::::::::::::::::::::::::::::::\n");
            printf(": Contact Number Should be 10 Digits :\n");
            printf("::::::::::::::::::::::::::::::::::::::\n\n");
            goto up;
        }
        // check from file
        id_flag2 = check_supplier_contact(s.s_contact);
        if (id_flag2 == 1)
        {
            printf("\n");
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(": Contact Number Already Exists ! Please Choose A Different One :\n");
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        }
    } while (id_flag2 == 1);

    // taking input of address
    printf("Enter the Supplier Address: ");
    scanf(" %[^\n]", s.s_address);

    // taking input of city
    printf("Enter the Supplier City: ");
    scanf(" %[^\n]", s.s_city);

    fwrite(&s, sizeof(struct supplier), 1, fptr);

    fclose(fptr);
    printf("\nQuery OK, %d rows affected.\n", 1);
    // printf("total %d Records.\n",cnt_supplier());
    return;
}
void print_product()
{ // print all data from products
    int tot = cnt_product();
    if (tot <= 0)
    {
        printf("Oops! It seems there are no products available. You Should Add One...\n");
    }
    else
    {
        struct product s;
        FILE *fptr;
        fptr = fopen("product.dat", "r");
        if (fptr == NULL)
        {
            printf("::::::::::::::::::::::::::::::");
            printf(": product.dat file not found :\n");
            printf("::::::::::::::::::::::::::::::");
            return;
        }
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while ((fread(&s, sizeof(struct product), 1, fptr)))
        {
            //  printf("| %d\t| %s\t\t| %s\t\t| %s\t\t| %d\t\t| %d\t\t| %d\t\t|\n", s.p_id, s.p_name, s.p_category, s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
            printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
            printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        }
        printf("%d record in set.\n", tot);
        fclose(fptr);
    }
    return;
}
void print_supplier()
{ // print all data from suppliers
    int tot = cnt_supplier();
    if (tot <= 0)
    {
        printf("Oops! It seems there are no Suppiler available. You Should Add One...");
    }
    else
    {
        struct supplier s;
        FILE *fptr;
        fptr = fopen("supplier.dat", "r");
        if (fptr == NULL)
        {
            printf("::::::::::::::::::::::::::::");
            printf("supplier.dat file not found.\n");
            printf("::::::::::::::::::::::::::::");
            return;
        }
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        printf("| Suppiler ID     | Suppiler Name               | Contact Number  | Address                        | City                 |\n");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");

        while ((fread(&s, sizeof(struct supplier), 1, fptr)))
        {
            printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s.s_id, s.s_name, s.s_contact, s.s_address, s.s_city);
            printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        }
        printf("%d record in set.\n", tot);
        fclose(fptr);
    }
}
void print_user()
{ // print all data from suppliers

    struct user s;
    FILE *fptr;
    fptr = fopen("user.dat", "r");
    if (fptr == NULL)
    {
        printf("::::::::::::::::::::::::::::");
        printf("supplier.dat file not found.\n");
        printf("::::::::::::::::::::::::::::");
        return;
    }
    while ((fread(&s, sizeof(struct user), 1, fptr)))
    {
        printf("| %-20s | %-10lld | %-30s |\n", s.u_name, s.u_contact, s.u_password);
    }

    fclose(fptr);
}
int cnt_product()
{ // return total record inside product.dat
    int cnt = 0;
    struct product s;
    FILE *fptr;
    fptr = fopen("product.dat", "r");
    while ((fread(&s, sizeof(struct product), 1, fptr)))
    {
        cnt++;
    }
    fclose(fptr);
    return cnt;
}
int cnt_supplier()
{ // return total record inside product.dat
    int cnt = 0;
    struct supplier s;
    FILE *fptr;
    fptr = fopen("supplier.dat", "r");
    while ((fread(&s, sizeof(struct supplier), 1, fptr)))
    {
        cnt++;
    }
    fclose(fptr);
    return cnt;
}
int check_product_id(int num)
{ // check id from product.dat return 1 if found
    FILE *fptr;
    struct product s;
    fptr = fopen("product.dat", "r");
    while (fread(&s, sizeof(struct product), 1, fptr))
    {
        if (s.p_id == num)
        {
            fclose(fptr);
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}
int check_supplier_id(int num)
{ // check id from supplier.dat return 1 if found
    FILE *fptr;
    struct supplier s;
    fptr = fopen("supplier.dat", "r");
    while (fread(&s, sizeof(struct supplier), 1, fptr))
    {
        if (s.s_id == num)
        {
            fclose(fptr);
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}
int check_supplier_contact(long long int num)
{ // check contect from suplier.dat
    FILE *fptr;
    struct supplier s;
    fptr = fopen("supplier.dat", "r");

    while (fread(&s, sizeof(struct supplier), 1, fptr))
    {
        if (s.s_contact == num)
        {
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}
int check_user_contact(long long int num)
{ // check contect from suplier.dat
    FILE *fptr;
    struct user s;
    fptr = fopen("user.dat", "r");

    while (fread(&s, sizeof(struct user), 1, fptr))
    {
        if (s.u_contact == num)
        {
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}
int check_p_category(int num)
{ // check category in 3 part 1 : Electronics || 2 : Mobile || 3 : Personal Computers[PC]
    int flag = 0;
    if (num != 1 && num != 2 && num != 3)
    {
        flag = 1;
    }
    return flag;
}
int check_p_category_and_price(int num)
{ // return 1 if number is wrong
    int flag = 0;
    if (num < 0)
    {
        flag = 1;
    }
    return flag;
}
int check_s_contact(long long int num)
{ // return 1 of number is wrong
    int count = 0, flag = 0;

    if (num < 0)
    {
        num = -num; // Convert negative number to positive
        count++;    // Increment count to account for '-' sign
    }
    // Count number of digits
    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    if (count != 10)
    {
        flag = 1;
    }
    return flag;
}
int check_product()
{ // return 1 if record found
    int cnt = 0;
    struct product s;
    FILE *fptr;
    fptr = fopen("product.dat", "r");
    while ((fread(&s, sizeof(struct product), 1, fptr)))
    {
        cnt = 1;
        break;
    }
    fclose(fptr);
    return cnt;
}
int check_supplier()
{ // return 1 if record found
    int cnt = 0;
    struct supplier s;
    FILE *fptr;
    fptr = fopen("supplier.dat", "r");
    while ((fread(&s, sizeof(struct supplier), 1, fptr)))
    {
        cnt = 1;
        break;
    }
    fclose(fptr);
    return cnt;
}
void advanced_p_name_search()
{ // search name form product
    if ((check_product()) == 1)
    {
        FILE *fptr;
        struct product s;
        char str[20];
        int cnt = 0;
        printf("Enter Prodcut Name : ");
        scanf(" %[^\n]", str);
        fptr = fopen("product.dat", "r");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (strncmp(s.p_name, str, strlen(str)) == 0)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, There Are No Products Like  %s :(\n", str);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available. You Should Add One...\n");
    }

    return;
}
void advanced_p_manufacturer_search()
{ // search manufacturer from product
    if ((check_product()) == 1)
    {
        FILE *fptr;
        struct product s;
        char str[20];
        int cnt = 0;
        printf("Enter Prodcut Manufacturer Name : ");
        scanf(" %[^\n]", str);
        fptr = fopen("product.dat", "r");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (strncmp(s.p_manufacturer, str, strlen(str)) == 0)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, There Are No Manufacturer Like  %s :(\n", str);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available. You Should Add One...\n");
    }

    return;
}
void p_quantity_search()
{ // search quantity form product base on min max value
    if (check_product() == 1)
    {
        FILE *fptr;
        struct product s;
        int min, max, flag = 0, cnt = 0;
        do
        {
            do
            {
                printf("Enter The Minimum Quantity: ");
                scanf("%d", &min);
                if (min < 0)
                {
                    printf("\n:::::::::::::::::::::::::\n");
                    printf(": Enter Positive Number :\n");
                    printf(":::::::::::::::::::::::::\n");
                }
                else
                {
                    break;
                }
            } while (1);
            do
            {
                printf("Enter The Maximum Quantity: ");
                scanf("%d", &max);
                if (max < 0)
                {
                    printf("\n:::::::::::::::::::::::::\n");
                    printf(": Enter Positive Number :\n");
                    printf(":::::::::::::::::::::::::\n");
                }
                else
                {
                    break;
                }
            } while (1);
            if (min > max)
            {
                flag = 1;
                printf("\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf(": The minimum value (%d) bigger the maximum value (%d). Please enter valid values :\n", min, max);
                printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            }
            else
            {
                break;
            }
        } while (1);
        fptr = fopen("product.dat", "r");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (s.p_quantity >= min && s.p_quantity <= max)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, there are no products available within the %d to %d range.", min, max);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available. You Shold Add One...\n");
    }
    return;
}
void p_price_search()
{ // search price form product base on min max value
    if (check_product() == 1)
    {
        FILE *fptr;
        struct product s;
        int min, max, flag = 0, cnt = 0;
        do
        {
            do
            {
                printf("Enter The Minimum Price: ");
                scanf("%d", &min);
                if (min < 0)
                {
                    printf("\n:::::::::::::::::::::::::\n");
                    printf(": Enter Positive Number :\n");
                    printf(":::::::::::::::::::::::::\n");
                }
                else
                {
                    break;
                }
            } while (1);
            do
            {
                printf("Enter the maximum price: ");
                scanf("%d", &max);
                if (max < 0)
                {
                    printf("\n:::::::::::::::::::::::::\n");
                    printf(": Enter Positive Number :\n");
                    printf(":::::::::::::::::::::::::\n");
                }
                else
                {
                    break;
                }
            } while (1);
            if (min > max)
            {
                flag = 1;
                printf("\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf(": The minimum value (%d) bigger the maximum value (%d). Please enter valid values :\n", min, max);
                printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            }
            else
            {
                break;
            }
        } while (1);
        fptr = fopen("product.dat", "r");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (s.p_price >= min && s.p_price <= max)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, there are no products available within the %d to %d range.", min, max);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available. You Should Add One...\n");
    }
    return;
}
void advanced_s_name_search()
{ // search supplier from name
    if ((check_supplier()) == 1)
    {
        FILE *fptr;
        struct supplier s;
        char str[20];
        int cnt = 0;
        printf("Enter Supplier Name : ");
        scanf(" %[^\n]", str);
        fptr = fopen("supplier.dat", "r");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        printf("| Suppiler ID     | Suppiler Name               | Contact Number  | Address                        | City                 |\n");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        while (fread(&s, sizeof(struct supplier), 1, fptr))
        {
            if (strncmp(s.s_name, str, strlen(str)) == 0)
            {
                printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s.s_id, s.s_name, s.s_contact, s.s_address, s.s_city);
                printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, there are no supplier like : %s [:(]\n", str);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no suppliers registered. You Should Add One...\n");
    }

    return;
}
void advanced_s_city_search()
{ // search supplier from city
    if ((check_supplier()) == 1)
    {
        FILE *fptr;
        struct supplier s;
        char str[20];
        int cnt = 0;
        printf("Enter supplier city : ");
        scanf(" %[^\n]", str);
        fptr = fopen("supplier.dat", "r");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        printf("| Suppiler ID     | Suppiler Name               | Contact Number  | Address                        | City                 |\n");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        while (fread(&s, sizeof(struct supplier), 1, fptr))
        {
            if (strncmp(s.s_city, str, strlen(str)) == 0)
            {
                printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s.s_id, s.s_name, s.s_contact, s.s_address, s.s_city);
                printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Unfortunately, there are no supplier in %s city :(\n", str);
        }
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no suppliers registered. You Should Add One...\n");
    }

    return;
}
void delete_p_row_product()
{ //remove row from product struct
    if (check_product() == 1)
    {
        FILE *fptr, *ftemp;
        struct product s;
        int cnt = 0;
        int r, t, cnt_delete = 0;
        do
        {
            printf("Enter Product ID : ");
            scanf("%d", &r);
            if (r <= 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
            }
            if (check_product_id(r) == 0)
            {
                printf("::::::::::::::::::::::::::::::::::\n");
                printf(": Product id %d id not avaliable : \n", r);
                printf("::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r <= 0 || check_product_id(r) == 0);

        fptr = fopen("product.dat", "r");
        if (fptr == NULL)
        {
            printf("File Opened Unsucsscfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "w");
        if (ftemp == NULL)
        {
            printf("File Opened Unsucssfully : \n");
            fclose(fptr);
            return;
        }
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            t = s.p_id;
            if (t != r)
            {
                fwrite(&s, sizeof(struct product), 1, ftemp);
            }
        }
        fclose(fptr);
        fclose(ftemp);

        fptr = fopen("product.dat", "w");
        if (fptr == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "rb");
        if (ftemp == NULL)
        {
            printf("File Opened Unsucssfully : \n");
            fclose(fptr);
            return;
        }
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, ftemp))
        {
            fwrite(&s, sizeof(struct product), 1, fptr);
            printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
            printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            cnt++;
        }
        fclose(fptr);
        fclose(ftemp);
        if (cnt == 0)
        {
            printf("Unfortunately, There are no supplier of %d id :(\n", r);
        }

        printf("OK, %d row affected\n", cnt_delete);
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available.You Should Add One...\n");
    }
    return;
}
void delete_p_row_supplier()
{ // remove supplier id from product
    if (check_product() == 1)
    {
        FILE *fptr, *ftemp;
        struct product s;
        int cnt = 0;
        int r, t, cnt_delete = 0;
        do
        {
            printf("Enter Supplier ID : ");
            scanf("%d", &r);
            if (r <= 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
            }
            else if (check_supplier_id(r) == 0)
            {
                printf("::::::::::::::::::::::::::::::::::\n");
                printf(": Product ID %d is not avaliable : \n", r);
                printf("::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r <= 0 || check_supplier_id(r) == 0);

        fptr = fopen("product.dat", "rb");
        if (fptr == NULL)
        {
            printf("File Opened Unsucsscfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "w");
        if (ftemp == NULL)
        {
            printf("File Opened Unsucssfully : \n");
            fclose(fptr);
            return;
        }
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            t = s.p_supplierid;
            if (t != r)
            {
                fwrite(&s, sizeof(struct product), 1, ftemp);
            }
            else
            {
                cnt_delete++;
            }
        }
        fclose(fptr);
        fclose(ftemp);

        fptr = fopen("product.dat", "w");
        if (fptr == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "rb");
        if (ftemp == NULL)
        {
            printf("File Opened Uncssesfully : \n");
            fclose(fptr);
            return;
        }
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        while (fread(&s, sizeof(struct product), 1, ftemp))
        {
            fwrite(&s, sizeof(struct product), 1, fptr);
            printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
            printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            cnt++;
        }
        fclose(fptr);
        fclose(ftemp);
        printf("OK, %d row affected\n", cnt_delete);
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no product registered.You Should Add One...\n");
    }
    return;
}
void update_p_quantity()
{ // update quantity of product
    if (check_product() == 1)
    {
        FILE *fptr, *ftemp;
        struct product s;
        int cnt = 0;
        int r, t, res;
        int ch;
        do
        {
            printf("Enter The Product Id  : ");
            scanf("%d", &r);
            if (r <= 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
            }

            else if (check_product_id(r) == 0)
            {
                printf("::::::::::::::::::::::::::::::::::\n");
                printf(": Product Id %d is not avaliable : \n", r);
                printf("::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r <= 0 || check_product_id(r) == 0);

        fptr = fopen("product.dat", "rb");
        if (fptr == NULL)
        {
            printf("File Opened Unsucsscfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "w");
        if (ftemp == NULL)
        {
            printf("File Opened Unsucssfully : \n");
            fclose(fptr);
            return;
        }
        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            t = s.p_id;
            if (t != r)
            {
                fwrite(&s, sizeof(struct product), 1, ftemp);
            }
            else
            {
                do
                {
                    printf("Enter Quantity to Update : \n");
                    scanf("%d", &ch);
                    if (ch <= 0)
                    {
                        printf("\n");
                        printf(":::::::::::::::::::::::::\n");
                        printf(": Enter Positive Number :\n");
                        printf(":::::::::::::::::::::::::\n\n");
                    }
                } while (ch <= 0);
                s.p_quantity = ch;
                fwrite(&s, sizeof(struct product), 1, ftemp);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }
        fclose(fptr);
        fclose(ftemp);

        fptr = fopen("product.dat", "w");
        if (fptr == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            return;
        }
        ftemp = fopen("temp1.txt", "rb");
        if (ftemp == NULL)
        {
            printf("File Opened Uncssesfully : \n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct product), 1, ftemp))
        {
            fwrite(&s, sizeof(struct product), 1, fptr);
        }

        fclose(fptr);
        fclose(ftemp);
        if (cnt == 0)
        {
            printf("Unfortunately, there are no product of %d price :(\n", r);
        }
        printf("Record Update Succeesfully : \n");
        printf("Found %d records out of %d.\n", cnt, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available.You Should Add One...\n");
    }
    return;
}
void update_p_price()
{ // update the product price by product id
    if (check_product() == 1)
    {
        FILE *fptr, *ftemp;
        struct product s;
        int cnt = 0;
        int r, ch;

        do
        {
            printf("Enter The Product ID : ");
            scanf("%d", &r);
            if (r <= 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
            }
            else if (check_product_id(r) == 0)
            {
                printf("::::::::::::::::::::::::::::::::::\n");
                printf(": Product ID %d is not available : \n", r);
                printf("::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r <= 0 || check_product_id(r) == 0);

        fptr = fopen("product.dat", "r");
        if (fptr == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            return;
        }

        ftemp = fopen("temp1.txt", "w");
        if (ftemp == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (s.p_id != r)
            {
                fwrite(&s, sizeof(struct product), 1, ftemp);
            }
            else
            {
                do
                {
                    printf("Enter Price to Update : ");
                    scanf("%d", &ch);
                    if (ch <= 0)
                    {
                        printf("\n");
                        printf(":::::::::::::::::::::::::\n");
                        printf(": Enter Positive Number :\n");
                        printf(":::::::::::::::::::::::::\n\n");
                    }
                } while (ch <= 0);
                s.p_price = ch;
                fwrite(&s, sizeof(struct product), 1, ftemp);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }

        fclose(fptr);
        fclose(ftemp);

        fptr = fopen("product.dat", "w");
        if (fptr == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            return;
        }

        ftemp = fopen("temp1.txt", "r");
        if (ftemp == NULL)
        {
            printf("File Opened Unsuccessfully : \n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct product), 1, ftemp))
        {
            fwrite(&s, sizeof(struct product), 1, fptr);
        }

        fclose(fptr);
        fclose(ftemp);

        if (cnt == 0)
        {
            printf("Unfortunately, there are no products with ID %d.\n", r);
        }
        else
        {
            printf("Record updated successfully for Product ID %d.\n", r);
            printf("Found %d records out of %d.\n", cnt, cnt_product());
        }
    }
    else
    {
        printf("Oops! It seems there are no products available. You should add one...\n");
    }
    return;
}
void update_p_name()
{ // update product name by product id

    if (check_product() == 1)
    {
        FILE *fptr, *ftemp;
        struct product s;
        int cnt = 0;
        int r;

        do
        {
            printf("Enter The Product ID : ");
            scanf("%d", &r);
            if (r < 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::::\n");
                printf(": Enter a positive number :\n");
                printf(":::::::::::::::::::::::::::\n\n");
            }
            else if (check_product_id(r) == 0)
            {
                printf(":::::::::::::::::::::::::::::::::::::::\n");
                printf(": Product with ID %d is not available : \n", r);
                printf(":::::::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r <= 0 || check_product_id(r) == 0);

        fptr = fopen("product.dat", "rb");
        if (fptr == NULL)
        {
            printf("Error opening product.dat for reading.\n");
            return;
        }

        ftemp = fopen("temp1.txt", "wb");
        if (ftemp == NULL)
        {
            printf("Error opening temp1.txt for writing.\n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct product), 1, fptr))
        {
            if (s.p_id != r)
            {
                fwrite(&s, sizeof(struct product), 1, ftemp);
            }
            else
            {
                printf("Enter new product name : ");
                scanf(" %[^\n]", s.p_name);
                fwrite(&s, sizeof(struct product), 1, ftemp);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", s.p_id, s.p_name, (s.p_category == 1 ? "Electronics" : (s.p_category == 2 ? "Mobile" : "Personal Computers[PC]")), s.p_manufacturer, s.p_quantity, s.p_price, s.p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
                cnt++;
            }
        }

        fclose(fptr);
        fclose(ftemp);

        fptr = fopen("product.dat", "wb");
        if (fptr == NULL)
        {
            printf("Error opening product.dat for writing.\n");
            return;
        }

        ftemp = fopen("temp1.txt", "rb");
        if (ftemp == NULL)
        {
            printf("Error opening temp1.txt for reading.\n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct product), 1, ftemp))
        {
            fwrite(&s, sizeof(struct product), 1, fptr);
        }

        fclose(fptr);
        fclose(ftemp);

        if (cnt == 0)
        {
            printf("Unfortunately, there are no products with ID %d :(\n", r);
        }
        else
        {
            printf("Record updated successfully.\n");
            printf("Found %d records out of %d.\n", cnt, cnt_product());
        }
    }
    else
    {
        printf("Uh-oh! It appears there are no products registered. You should add one...\n");
    }
}
void update_s_name()
{
    if (cnt_supplier() > 0)
    {
        FILE *fptr, *ftemp;
        struct supplier s;
        int cnt = 0;
        int r;

        do
        {
            printf("Enter The supplier ID: ");
            scanf("%d", &r);
            if (r < 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::::\n");
                printf(": Enter a positive number :\n");
                printf(":::::::::::::::::::::::::::\n\n");

            }
            else if (check_supplier_id(r) == 0)
            {
                printf(":::::::::::::::::::::::::::::::::::::::\n");
                printf(": Product with ID %d is not available : \n", r);
                printf(":::::::::::::::::::::::::::::::::::::::\n\n");
            }
        } while (r < 0 || check_supplier_id(r) == 0);

        fptr = fopen("supplier.dat", "rb");
        if (fptr == NULL)
        {
            printf("Error opening supplier.dat for reading.\n");
            return;
        }

        ftemp = fopen("temp1.dat", "wb");
        if (ftemp == NULL)
        {
            printf("Error opening temp1.dat for writing.\n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct supplier), 1, fptr))
        {
            if (s.s_id != r)
            {
                fwrite(&s, sizeof(struct supplier), 1, ftemp);
            }
            else
            {
                printf("Enter new supplier name: ");
                scanf(" %[^\n]", s.s_name);
                fwrite(&s, sizeof(struct supplier), 1, ftemp);
                printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
                printf("| Suppiler ID     | Suppiler Name               | Contact Number  | Address                        | City                 |\n");
                printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
                printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s.s_id, s.s_name, s.s_contact, s.s_address, s.s_city);
                printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
                cnt++;
            }
        }

        fclose(fptr);
        fclose(ftemp);

        remove("supplier.dat");
        rename("temp1.dat", "supplier.dat");

        if (cnt == 0)
        {
            printf("No suppliers with ID %d were found.\n", r);
        }
        else
        {
            printf("Record updated successfully.\n");
            printf("Updated %d records out of %d.\n", cnt, cnt_supplier());
        }
    }
    else
    {
        printf("No suppliers registered. Please add a supplier.\n");
    }
}
int check_supplier_id_from_product(int r){
    FILE *fptr;
    struct product s;
    int flag = 0;
    fptr = fopen("product.dat","r");
    while(fread(&s,sizeof(struct product),1,fptr)){
        if(s.p_supplierid == r){
            flag = 1;
            break;
        }
    }
    return flag;
}
void delete_s_id_supplier() { //delete supplier data from supplier 
    if(cnt_supplier() > 0) {
        FILE *fptr, *ftemp;
        struct supplier s;
        int r, found = 0, cnt = 0;
        do{
         printf("Enter the Supplier ID to delete: ");
         scanf("%d", &r);
          if (r < 0)
            {
                printf("\n");
                printf(":::::::::::::::::::::::::\n");
                printf(": Enter Positive Number :\n");
                printf(":::::::::::::::::::::::::\n\n");
            }
            else if (check_supplier_id(r) == 0)
            {
                printf(":::::::::::::::::::::::::::::::::::\n");
                printf(": supplier ID %d is not avaliable : \n", r);
                printf(":::::::::::::::::::::::::::::::::::\n\n");
            }
        }
        while(r<0 || check_supplier_id(r) == 0 );
        
        if(check_supplier_id_from_product(r) == 1){
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(": supplier ID %d is avaliable in product ! so this supplier data can`t delete : \n", r);
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
            return;
        }

        fptr = fopen("supplier.dat", "r");
        if (fptr == NULL) {
            printf("Error opening supplier.dat for reading.\n");
            return;
        }

        ftemp = fopen("temp.dat", "w");
        if (ftemp == NULL) {
            printf("Error opening temp.dat for writing.\n");
            fclose(fptr);
            return;
        }

        while (fread(&s, sizeof(struct supplier), 1, fptr)) {
            if (s.s_id == r) {
                found = 1;
                cnt++;
            } else {
                fwrite(&s, sizeof(struct supplier), 1, ftemp);
            }
        }

        fclose(fptr);
        fclose(ftemp);

        if (!found) {
            printf("Supplier with ID %d not found.\n", r);
            remove("temp.dat");
        } else {
            remove("supplier.dat");
            rename("temp.dat", "supplier.dat");
            printf("Supplier with ID %d deleted successfully.\n", r);
            printf("Found %d records out of %d.\n", cnt, cnt_supplier());
        }

    } else {
        printf("Uh-oh! It appears there are no suppliers registered. You should add one.\n");
    }
}
void short_p_name_asending()
{ // shorting by product name
    if (check_product() == 1)
    {
        FILE *fptr;
        struct product *s, temp;
        int i, j;
        int size = cnt_product();
        if (size <= 0)
        {
            printf("No products found.\n");
            return;
        }
        s = (struct product *)calloc(size, sizeof(struct product));
        if (s == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        fptr = fopen("product.dat", "r");
        if (fptr == NULL)
        {
            printf("File opened unsuccessfully.\n");
            free(s);
            return;
        }
        for (i = 0; i < size; i++)
        {
            fread(&s[i], sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        char a[size][50];
        for (i = 0; i < size; i++)
        {
            strcpy(a[i], s[i].p_name);
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size - 1; j++)
            {
                if (strcmp(a[j], a[j + 1]) > 0)
                {
                    strcpy(temp.p_name, a[j]);
                    strcpy(a[j], a[j + 1]);
                    strcpy(a[j + 1], temp.p_name);
                }
            }
        }
        struct product *sorted = (struct product *)calloc(size, sizeof(struct product));
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (strcmp(a[i], s[j].p_name) == 0)
                {
                    sorted[i] = s[j];
                    break;
                }
            }
        }
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", sorted[i].p_id, sorted[i].p_name, (sorted[i].p_category == 1 ? "Electronics" : (sorted[i].p_category == 2 ? "Mobile" : "Personal Computers[PC]")), sorted[i].p_manufacturer, sorted[i].p_quantity, sorted[i].p_price, sorted[i].p_supplierid);
            printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        }
        free(s);
        free(sorted);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available.You Should Add One?\n");
    }
    return;
}
void short_p_name_desending()
{ // shorting by product name
    if (check_product() == 1)
    {
        FILE *fptr;
        struct product *s, temp;
        int i, j;
        int size = cnt_product();
        if (size <= 0)
        {
            printf("No products found.\n");
            return;
        }
        s = (struct product *)calloc(size, sizeof(struct product));
        if (s == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        fptr = fopen("product.dat", "r");
        if (fptr == NULL)
        {
            printf("File opened unsuccessfully.\n");
            free(s);
            return;
        }
        for (i = 0; i < size; i++)
        {
            fread(&s[i], sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        char a[size][50];
        for (i = 0; i < size; i++)
        {
            strcpy(a[i], s[i].p_name);
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size - 1; j++)
            {
                if (strcmp(a[j], a[j + 1]) < 0)
                {
                    strcpy(temp.p_name, a[j]);
                    strcpy(a[j], a[j + 1]);
                    strcpy(a[j + 1], temp.p_name);
                }
            }
        }
        struct product *sorted = (struct product *)calloc(size, sizeof(struct product));
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (strcmp(a[i], s[j].p_name) == 0)
                {
                    sorted[i] = s[j];
                    break;
                }
            }
        }
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", sorted[i].p_id, sorted[i].p_name, (sorted[i].p_category == 1 ? "Electronics" : (sorted[i].p_category == 2 ? "Mobile" : "Personal Computers[PC]")), sorted[i].p_manufacturer, sorted[i].p_quantity, sorted[i].p_price, sorted[i].p_supplierid);
            printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        }
        free(s);
        free(sorted);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Oops! It seems there are no products available. You Should Add One\n");
    }
    return;
}
void short_s_name_asending(){
    if(cnt_supplier() > 0){
        FILE *fptr;
        struct supplier *s,temp;
        int i,j;
        int size =cnt_supplier();
        if(size <= 0){
            printf("No supplier found. \n");
            return ;
        }

        s = (struct supplier *)calloc(size,sizeof(struct supplier));
        if(s == NULL){
            printf("Memory alocation falied.\n");
            return ;
        }
        fptr=fopen("supplier.dat","r");
        if(fptr == NULL){
            printf("File opened unsccessfully.\n");
            free(s);
            return ;
        }
        for(i = 0;i < size ; i++){
            fread(&s[i],sizeof(struct product),1,fptr);
        }
        fclose(fptr);

        char a[size][50];
        for(i = 0; i < size ; i++){
            strcpy(a[i],s[i].s_name);
        }
        for(i = 0; i < size ; i++){
            for(j = 0 ; j < size ; j++){
                if(strcmp(a[j] ,a[ j + 1]) > 0){
                    strcpy(temp.s_name,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],temp.s_name);
                }
            }
        }
        struct supplier *sorted = (struct supplier *)calloc(size, sizeof(struct supplier));
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(strcmp(a[i],s[j].s_name) == 0){
                    sorted[i] = s[j];
                    break;
                }
            }
        }
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        printf("| Supplier ID     | Supplier Name               | Contact Number  | Address                        | City                 |\n");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");

        for (i = 0; i < size; i++) {
            printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s[i].s_id, s[i].s_name, s[i].s_contact, s[i].s_address, s[i].s_city);
            printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        }
        free(s);
        free(sorted);
        printf("Found %d records out of %d.\n", size, cnt_product());

    }
    else{
    printf("Oops! It seems there are no products available. You Should Add One\n");   
    }
    return ;
}
void short_s_name_desending(){
    if(cnt_supplier() > 0){
        FILE *fptr;
        struct supplier *s,temp;
        int i,j;
        int size =cnt_supplier();
        if(size <= 0){
            printf("No supplier found. \n");
            return ;
        }

        s = (struct supplier *)calloc(size,sizeof(struct supplier));
        if(s == NULL){
            printf("Memory alocation falied.\n");
            return ;
        }
        fptr=fopen("supplier.dat","r");
        if(fptr == NULL){
            printf("File opened unsccessfully.\n");
            free(s);
            return ;
        }
        for(i = 0;i < size ; i++){
            fread(&s[i],sizeof(struct product),1,fptr);
        }
        fclose(fptr);

        char a[size][50];
        for(i = 0; i < size ; i++){
            strcpy(a[i],s[i].s_name);
        }
        for(i = 0; i < size ; i++){
            for(j = 0 ; j < size ; j++){
                if(strcmp(a[j] ,a[ j + 1]) < 0){
                    strcpy(temp.s_name,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],temp.s_name);
                }
            }
        }
        struct supplier *sorted = (struct supplier *)calloc(size, sizeof(struct supplier));
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(strcmp(a[i],s[j].s_name) == 0){
                    sorted[i] = s[j];
                    break;
                }
            }
        }
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        printf("| Supplier ID     | Supplier Name               | Contact Number  | Address                        | City                 |\n");
        printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");

        for (i = 0; i < size; i++) {
            printf("| %-15d | %-27s | %-15lld | %-30s | %-20s |\n", s[i].s_id, s[i].s_name, s[i].s_contact, s[i].s_address, s[i].s_city);
            printf("+-----------------+-----------------------------+-----------------+--------------------------------+----------------------+\n");
        }
        free(s);
        free(sorted);
        printf("Found %d records out of %d.\n", size, cnt_product());

    }
    else{
    printf("Oops! It seems there are no products available. You Should Add One\n");   
    }
    return ;
}
void short_P_price_asending()
{ // shorting by product price

    if (check_product() == 1)
    {
        FILE *fptr;
        int i, j, c, t;
        int size = cnt_product();
        struct product *s, temp;
        s = (struct product *)calloc(size, sizeof(struct product));
        fptr = fopen("product.dat", "r");
        for (i = 0; i < size; i++)
        {
            fread(s + i, sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        c = size;
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {
                if ((s + j)->p_price > (s + j + 1)->p_price)
                {
                    temp = *(s + j);
                    *(s + j) = *(s + j + 1);
                    *(s + j + 1) = temp;
                }
            }
        }
        int cnt = 0;
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            for (i = 0; i < size; i++)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", (s + i)->p_id, (s + i)->p_name, ((s + i)->p_category == 1 ? "Electronics" : ((s + i)->p_category == 2 ? "Mobile" : "Personal Computers[PC]")), (s + i)->p_manufacturer, (s + i)->p_quantity, (s + i)->p_price, (s + i)->p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            }
            cnt++;
        }

        free(s);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no product registered.You Should Add One...\n");
    }
}
void short_P_price_desending()
{ // shorting by product price
    if (check_product() == 1)
    {
        FILE *fptr;
        int i, j, c, t;
        int size = cnt_product();
        struct product *s, temp;
        s = (struct product *)calloc(size, sizeof(struct product));
        fptr = fopen("product.dat", "r");
        for (i = 0; i < size; i++)
        {
            fread(s + i, sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        c = size;
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {
                if ((s + j)->p_price < (s + j + 1)->p_price)
                {
                    temp = *(s + j);
                    *(s + j) = *(s + j + 1);
                    *(s + j + 1) = temp;
                }
            }
        }
        int cnt = 0;
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            for (i = 0; i < size; i++)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", (s + i)->p_id, (s + i)->p_name, ((s + i)->p_category == 1 ? "Electronics" : ((s + i)->p_category == 2 ? "Mobile" : "Personal Computers[PC]")), (s + i)->p_manufacturer, (s + i)->p_quantity, (s + i)->p_price, (s + i)->p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            }
            cnt++;
        }

        free(s);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no product registered. You Should Add One...\n");
    }
}
void short_p_quntity_asending()
{ // shorting by product quantity
    if (check_product() == 1)
    {
        FILE *fptr;
        int i, j, c, t;
        int size = cnt_product();
        struct product *s, temp;
        s = (struct product *)calloc(size, sizeof(struct product));
        fptr = fopen("product.dat", "r");
        for (i = 0; i < size; i++)
        {
            fread(s + i, sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        c = size;
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {
                if ((s + j)->p_quantity > (s + j + 1)->p_quantity)
                {
                    temp = *(s + j);
                    *(s + j) = *(s + j + 1);
                    *(s + j + 1) = temp;
                }
            }
        }
        int cnt = 0;
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            for (i = 0; i < size; i++)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", (s + i)->p_id, (s + i)->p_name, ((s + i)->p_category == 1 ? "Electronics" : ((s + i)->p_category == 2 ? "Mobile" : "Personal Computers[PC]")), (s + i)->p_manufacturer, (s + i)->p_quantity, (s + i)->p_price, (s + i)->p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            }
            cnt++;
        }

        free(s);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no product registered.You Should Add One...\n");
    }
}
void short_p_quntity_desending()
{ // shorting by product quantity
    if (check_product() == 1)
    {
        FILE *fptr;
        int i, j, c, t;
        int size = cnt_product();
        struct product *s, temp;
        s = (struct product *)calloc(size, sizeof(struct product));
        fptr = fopen("product.dat", "r");
        for (i = 0; i < size; i++)
        {
            fread(s + i, sizeof(struct product), 1, fptr);
        }
        fclose(fptr);
        c = size;
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {
                if ((s + j)->p_quantity < (s + j + 1)->p_quantity)
                {
                    temp = *(s + j);
                    *(s + j) = *(s + j + 1);
                    *(s + j + 1) = temp;
                }
            }
        }
        int cnt = 0;
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        printf("| Product ID | Product Name         | Product Category          | Manufacturer Name    | Quantity      | Price         | Supplier Id   |\n");
        printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
        for (i = 0; i < size; i++)
        {
            for (i = 0; i < size; i++)
            {
                printf("| %-10d | %-20s | %-25s | %-20s | %-13d | %-13d | %-13d |\n", (s + i)->p_id, (s + i)->p_name, ((s + i)->p_category == 1 ? "Electronics" : ((s + i)->p_category == 2 ? "Mobile" : "Personal Computers[PC]")), (s + i)->p_manufacturer, (s + i)->p_quantity, (s + i)->p_price, (s + i)->p_supplierid);
                printf("+------------+----------------------+---------------------------+----------------------+---------------+---------------+---------------+\n");
            }
            cnt++;
        }

        free(s);
        printf("Found %d records out of %d.\n", size, cnt_product());
    }
    else
    {
        printf("Uh-oh! It appears there are no Product registered. You Should Add One...\n");
    }
}