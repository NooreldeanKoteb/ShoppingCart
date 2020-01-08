#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Item_struct{ //Struct defined
    char Item_name[25]; //name of item
    size_t quantity; //quantity of item
    double price; //price of item
};

void ResizeArray(struct Item_struct *ShoppingCart, int *size){ //resize function
    *size *=2; //doubles size
    int i; //defines i
    struct Item_struct* ShoppingCart2 = malloc(sizeof(struct Item_struct) * *size); //malloc for new array
    if (ShoppingCart2 == NULL){ // checks malloc
        printf("Error: Memory Allocation Failed, Too Many Items!\n"); //failure msg
        exit(1); //exit program
    }
    memcpy(ShoppingCart2, ShoppingCart, ((*size/2)*sizeof(struct Item_struct))); //copies values from old array to new array
    ShoppingCart = NULL;//no dangling error
    struct Item_struct* ShoppingCart = malloc(sizeof(struct Item_struct) * *size);//malloc old array with new size
    for(i=0; i<(*size/2);i++){ //values set back to old array from new array
    	ShoppingCart[i] = ShoppingCart2[i]; 
    }
    free(ShoppingCart2); // free new array

}
void PrintMenu(){ //Program Menu
    printf("We Want Your Money Shopping Cart!\n");
    printf("###################################\n");
    printf("Options:\n");
    printf("[1] - Add an item to ShoppingCart\n");
    printf("[2] - Print current ShoppingCart\n");
    printf("[3] - Quit\n");
    printf("###################################\n");
}
int main(){ //Main Function
    int option = 0; //defines variable
    int size = 0;//defines variable
    int pos = 0;//defines variable
    int i = 0;//defines variable
    char size_buff[100];//defines variable
    char option_buff[100];//defines variable
    char name_buff[25];//defines variable
    char quantity_buff[100];//defines variable
    char price_buff[100];//defines variable
    printf("How Big is your cart?\n");
    fgets(size_buff,100,stdin);//takes in size of cart
    sscanf(size_buff,"%d", &size);//sets input to size
    struct Item_struct* ShoppingCart = malloc(sizeof(struct Item_struct) * size); //malloc of array
    if (ShoppingCart == NULL){ //checks malloc
        printf("Error: Memory Intialization Failed!\n");
        exit(1);//exit program
    }
    while(option != 3){ //Loop for program
        PrintMenu(); //prints menu
        fgets(option_buff,100,stdin); //takes input
        sscanf(option_buff,"%d", &option); //sets it to options
        switch (option){ //switch for menu option
            case 1:
                if (pos > size-1){ //checks if there is space in array
                    ResizeArray(ShoppingCart, &size); //calls resizearray
                }
                if (pos < size){  //checks if there is space in array
                    printf("ItemName: ");
                    fgets(name_buff,25,stdin);//takes in name
                    sscanf(name_buff, "%s",& ShoppingCart[pos].Item_name);//saves name
                    printf("\nQuantity: ");
                    fgets(quantity_buff,100,stdin);//takes in quantity
                    sscanf(quantity_buff, "%zu", &ShoppingCart[pos].quantity); //saves quantity
                    printf("\nPrice: ");
                    fgets(price_buff,100,stdin);//takes in price
                    sscanf(price_buff, "%lf", &ShoppingCart[pos].price); //saves price
                    pos++;//increment
                }
                break;//restarts loop
            case 2:
                for (i=0; i<pos; i++){//goes through array & prints values from it
                    printf("Item %d: ", i+1);
                    printf("%zu ",ShoppingCart[i].quantity);
                    printf("%s ",ShoppingCart[i].Item_name);
                    printf("For $%3.2f \n",ShoppingCart[i].price);
                }
            break;
            case 3:
                free(ShoppingCart);// frees array
                exit(0);//exits program
            default:
                printf("Error: That Option Does Not Exist\nPlease Try Again!");
                PrintMenu();//prints menu
                break;
        }
    }
}
