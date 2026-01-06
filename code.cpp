#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

const string YELLOW = "\033[33m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

void showArray(int arr[], int n, int y, int pos1 = -1, int pos2 = -1, int sorted = -1)
 {
    gotoxy(6, y + 2);
    cout << "Array: [ ";
    for (int i = 0; i < n; i++)
    {
        gotoxy(15 + (i * 4), y + 2);
        if (i == pos1 || i == pos2)
        {
            cout << YELLOW << arr[i] << RESET << "   ";
        }
        else if (sorted != -1 && i >= sorted)
        {
            cout << GREEN << arr[i] << RESET << "   ";
        }
        else
        {
            cout << arr[i] << "   ";
        }
    }
    cout << "]";
 }
void highlightPositions(int pos1, int pos2, int y, int n)
 {
    gotoxy(15, y + 3);
    for (int i = 0; i < 60; i++) cout << " ";
    gotoxy(15, y + 3);
    for (int i = 0; i < n; i++)
    {
        if (i == pos1 || i == pos2)
        {
            cout << "^   ";
        }
        else
        {
            cout << "    ";
        }
    }
 }

void showMessage(string msg)
 {
    gotoxy(15, 5);
    for (int i = 0; i < 60; i++) cout << " ";
    gotoxy(15, 5);
    cout << msg;
 }

void showAnalysis(int n, int comparisons, int swaps, string algorithm)
 {
    int maxComparisons = (n * (n - 1)) / 2;
    int maxSwaps = (n * (n - 1)) / 2;
    
    gotoxy(15, 17);
    cout << "========================================";
    gotoxy(15, 18);
    cout << "     " << algorithm << " - ANALYSIS REPORT";
    gotoxy(15, 19);
    cout << "========================================";
    
    gotoxy(15, 21);
    cout << "Array Size: " << n;
    gotoxy(15, 22);
    cout << "Total Comparisons: " << comparisons;
    gotoxy(15, 23);
    cout << "Total Swaps: " << swaps;
    
    gotoxy(15, 25);
    if (algorithm == "MERGE SORT" || algorithm == "QUICK SORT")
        cout << "Time Complexity: O(n log n)";
    else
        cout << "Time Complexity: O(n^2)";
    
    gotoxy(15, 26);
    if (algorithm == "MERGE SORT")
        cout << "Space Complexity: O(n)";
    else
        cout << "Space Complexity: O(1)";
 }

void bubbleSortVisualize(int arr[], int n)
 {
    gotoxy(15, 2);
    cout << "========================================";
    gotoxy(15, 3);
    cout << "\033[31m  BUBBLE SORT VISUALIZATION\033[0m";
    gotoxy(15, 4);
    cout << "========================================";
    int arrayY = 8;
    int statsY = 13;
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool sorted=false;
        showMessage("PASS " + to_string(i + 1));
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            showArray(arr, n, arrayY, j, j + 1, n - i);
            highlightPositions(j, j + 1, arrayY, n);
            gotoxy(0,0);
            Sleep(600);

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                showArray(arr, n, arrayY, j, j + 1, n - i);
                highlightPositions(j, j + 1, arrayY, n);
                gotoxy(0,0);
                Sleep(800);
                sorted=true;
            }
            else
            {
                gotoxy(0,0);
                Sleep(400);
            }
            
            gotoxy(15, statsY);
            cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << "   ";
        }
        if(!sorted)
            break;
        showArray(arr, n, arrayY, -1, -1, n - i - 1);
        highlightPositions(-1, -1, arrayY, n);
        gotoxy(0,0);
        Sleep(1000);
    }
    
    showArray(arr, n, arrayY, -1, -1, 0);
    highlightPositions(-1, -1, arrayY, n);
    showAnalysis(n, comparisons, swaps, "BUBBLE SORT");
 }

void insertionSortVisualize(int arr[], int n)
{
    gotoxy(15, 2);
    cout << "========================================";
    gotoxy(15, 3);
    cout << "\033[31m  INSERTION SORT VISUALIZATION\033[0m";
    gotoxy(15, 4);
    cout << "========================================";
    int arrayY = 8;
    int statsY = 13;
    int comparisons = 0, swaps = 0;

    for (int i = 1; i < n; i++)
    {
        showMessage("Inserting element at position " + to_string(i));
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;
            showArray(arr, n, arrayY, j, j + 1, -1);
            highlightPositions(j, j + 1, arrayY, n);
            gotoxy(0,0);
            Sleep(600);

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swaps++;
                showArray(arr, n, arrayY, j, j + 1, -1);
                highlightPositions(j, j + 1, arrayY, n);
                gotoxy(0,0);
                Sleep(800);
                j--;
            }
            else
            {
                break;
            }

            gotoxy(15, statsY);
            cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << "   ";
        }
        arr[j + 1] = key;
        showArray(arr, n, arrayY, -1, -1, -1);
        Sleep(500);
    }
    
    showArray(arr, n, arrayY, -1, -1, 0);
    highlightPositions(-1, -1, arrayY, n);
    showAnalysis(n, comparisons, swaps, "INSERTION SORT");
}

void selectionSortVisualize(int arr[], int n)
{
    gotoxy(15, 2);
    cout << "========================================";
    gotoxy(15, 3);
    cout << "\033[31m  SELECTION SORT VISUALIZATION\033[0m";
    gotoxy(15, 4);
    cout << "========================================";
    int arrayY = 8;
    int statsY = 13;
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        showMessage("Finding minimum from position " + to_string(i));
        int minIdx = i;
        
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            showArray(arr, n, arrayY, minIdx, i, -1);
            highlightPositions(minIdx, j, arrayY, n);
            gotoxy(0,0);
            Sleep(600);

            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }

            gotoxy(15, statsY);
            cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << "   ";
        }

        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            swaps++;
            showArray(arr, n, arrayY, i, minIdx, -1);
            highlightPositions(i, minIdx, arrayY, n);
            gotoxy(0,0);
            Sleep(800);
        }
        
        showArray(arr, n, arrayY, -1, -1, -1);
        Sleep(500);
    }
    
    showArray(arr, n, arrayY, -1, -1, 0);
    highlightPositions(-1, -1, arrayY, n);
    showAnalysis(n, comparisons, swaps, "SELECTION SORT");
}

int partition(int arr[], int low, int high, int n, int arrayY, int statsY, int &comparisons, int &swaps)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        showArray(arr, n, arrayY, j, high, -1);
        highlightPositions(j, high, arrayY, n);
        gotoxy(0,0);
        Sleep(400);

        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;
            showArray(arr, n, arrayY, i, j, -1);
            highlightPositions(i, j, arrayY, n);
            gotoxy(0,0);
            Sleep(600);
        }

        gotoxy(15, statsY);
        cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << "   ";
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    swaps++;
    showArray(arr, n, arrayY, i + 1, high, -1);
    highlightPositions(i + 1, high, arrayY, n);
    gotoxy(0,0);
    Sleep(600);

    return i + 1;
}

void quickSortHelper(int arr[], int low, int high, int n, int arrayY, int statsY, int &comparisons, int &swaps)
{
    if (low < high)
    {
        showMessage("Quick Sort: Partitioning [" + to_string(low) + " to " + to_string(high) + "]");
        int pi = partition(arr, low, high, n, arrayY, statsY, comparisons, swaps);
        quickSortHelper(arr, low, pi - 1, n, arrayY, statsY, comparisons, swaps);
        quickSortHelper(arr, pi + 1, high, n, arrayY, statsY, comparisons, swaps);
    }
}

void quickSortVisualize(int arr[], int n)
{
    gotoxy(15, 2);
    cout << "========================================";
    gotoxy(15, 3);
    cout << "\033[31m  QUICK SORT VISUALIZATION";
    gotoxy(15, 4);
    cout << "========================================";
    int arrayY = 8;
    int statsY = 13;
    int comparisons = 0, swaps = 0;

    quickSortHelper(arr, 0, n - 1, n, arrayY, statsY, comparisons, swaps);
    
    showArray(arr, n, arrayY, -1, -1, 0);
    highlightPositions(-1, -1, arrayY, n);
    showAnalysis(n, comparisons, swaps, "QUICK SORT");
}

void merge(int arr[], int left, int mid, int right, int n, int arrayY, int statsY, int &comparisons, int &swaps)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comparisons++;
        showArray(arr, n, arrayY, left + i, mid + 1 + j, -1);
        highlightPositions(left + i, mid + 1 + j, arrayY, n);
        gotoxy(0,0);
        Sleep(400);

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        swaps++;
        k++;

        gotoxy(15, statsY);
        cout << "Comparisons: " << comparisons << " | Merges: " << swaps << "   ";
        showArray(arr, n, arrayY, k - 1, -1, -1);
        Sleep(400);
    }

    while (i < n1)
    {
        arr[k] = L[i];
        swaps++;
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        swaps++;
        j++;
        k++;
    }
}

void mergeSortHelper(int arr[], int left, int right, int n, int arrayY, int statsY, int &comparisons, int &swaps)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        showMessage("Merge Sort: Dividing [" + to_string(left) + " to " + to_string(right) + "]");
        mergeSortHelper(arr, left, mid, n, arrayY, statsY, comparisons, swaps);
        mergeSortHelper(arr, mid + 1, right, n, arrayY, statsY, comparisons, swaps);
        showMessage("Merge Sort: Merging [" + to_string(left) + " to " + to_string(right) + "]");
        merge(arr, left, mid, right, n, arrayY, statsY, comparisons, swaps);
    }
}

void mergeSortVisualize(int arr[], int n)
{
    gotoxy(15, 2);
    cout << "========================================";
    gotoxy(15, 3);
    cout << "  MERGE SORT VISUALIZATION";
    gotoxy(15, 4);
    cout << "========================================";
    int arrayY = 8;
    int statsY = 13;
    int comparisons = 0, swaps = 0;

    mergeSortHelper(arr, 0, n - 1, n, arrayY, statsY, comparisons, swaps);
    
    showArray(arr, n, arrayY, -1, -1, 0);
    highlightPositions(-1, -1, arrayY, n);
    showAnalysis(n, comparisons, swaps, "MERGE SORT");
}

void bubbleSortSimple(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSortSimple(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSortSimple(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void mergeSortSimple(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortSimple(arr, left, mid);
        mergeSortSimple(arr, mid + 1, right);
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];
        
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }
}

int partitionSimple(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSortSimple(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionSimple(arr, low, high);
        quickSortSimple(arr, low, pi - 1);
        quickSortSimple(arr, pi + 1, high);
    }
}

void displaySortedArray(int arr[], int n)
{
    system("cls");
    gotoxy(15, 5);
    cout << GREEN << "========================================" << RESET;
    gotoxy(15, 6);
    cout << GREEN << "      SORTING COMPLETED!" << RESET;
    gotoxy(15, 7);
    cout << GREEN << "========================================" << RESET;
    
    gotoxy(15, 9);
    cout << "Sorted Array: ";
    gotoxy(15, 11);
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << GREEN << arr[i] << RESET;
        if (i < n - 1)
            cout << ", ";
    }
    cout << " ]";
    
    gotoxy(15, 14);
    cout << "Press any key to return to main menu...";
    getch();
}

void sortDataMenu()
{
    system("cls");
    int size;
    gotoxy(15, 3);
    cout << BLUE << "========================================" << RESET;
    gotoxy(15, 4);
    cout << BLUE << "          SORT DATA MODE" << RESET;
    gotoxy(15, 5);
    cout << BLUE << "========================================" << RESET;
    
    gotoxy(15, 7);
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[size];
    gotoxy(15, 9);
    cout << "Enter " << size << " elements:";
    for (int i = 0; i < size; i++)
    {
        gotoxy(15, 11 + i);
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    system("cls");
    gotoxy(15, 3);
    cout << "========================================";
    gotoxy(15, 4);
    cout << "    SELECT SORTING ALGORITHM";
    gotoxy(15, 5);
    cout << "========================================";
    gotoxy(15, 7);
    cout << "1. Bubble Sort";
    gotoxy(15, 8);
    cout << "2. Insertion Sort";
    gotoxy(15, 9);
    cout << "3. Selection Sort";
    gotoxy(15, 10);
    cout << "4. Merge Sort";
    gotoxy(15, 11);
    cout << "5. Quick Sort";
    gotoxy(15, 13);
    cout << "Enter your choice (1-5): ";
    
    int choice;
    cin >> choice;
    
    system("cls");
    gotoxy(15, 8);
    cout << "Sorting in progress...";
    Sleep(1000);
    
    switch(choice)
    {
        case 1:
            bubbleSortSimple(arr, size);
            break;
        case 2:
            insertionSortSimple(arr, size);
            break;
        case 3:
            selectionSortSimple(arr, size);
            break;
        case 4:
            mergeSortSimple(arr, 0, size - 1);
            break;
        case 5:
            quickSortSimple(arr, 0, size - 1);
            break;
        default:
            gotoxy(15, 10);
            cout << RED << "Invalid choice!" << RESET;
            Sleep(2000);
            return;
    }
    
    displaySortedArray(arr, size);
}

void generateArray(int arr[], int size, int caseType)
{
    srand(time(0));
    
    if (caseType == 1) // Best Case - Already Sorted
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = (i + 1) * 5;
        }
    }
    else if (caseType == 2) // Worst Case - Reverse Sorted
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = (size - i) * 5;
        }
    }
    else // Average Case - Random
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 99 + 1;
        }
    }
}

void visualizeSortingMenu()
{
    system("cls");
    int size;
    gotoxy(15, 3);
    cout << BLUE << "========================================" << RESET;
    gotoxy(15, 4);
    cout << BLUE << "     VISUALIZE SORTING MODE" << RESET;
    gotoxy(15, 5);
    cout << BLUE << "========================================" << RESET;
    
    gotoxy(15, 7);
    cout << "Enter the size of array (max 15): ";
    cin >> size;
    
    if (size > 15)
    {
        gotoxy(15, 9);
        cout << RED << "Size too large for visualization! Using 15." << RESET;
        size = 15;
        Sleep(2000);
    }
    
    system("cls");
    gotoxy(15, 3);
    cout << "========================================";
    gotoxy(15, 4);
    cout << "       SELECT TEST CASE TYPE";
    gotoxy(15, 5);
    cout << "========================================";
    gotoxy(15, 7);
    cout << "1. Best Case (Already Sorted)";
    gotoxy(15, 8);
    cout << "2. Worst Case (Reverse Sorted)";
    gotoxy(15, 9);
    cout << "3. Average Case (Random)";
    gotoxy(15, 11);
    cout << "Enter your choice (1-3): ";
    
    int caseChoice;
    cin >> caseChoice;
    
    int originalArr[size];
    generateArray(originalArr, size, caseChoice);
    
    gotoxy(15, 13);
    cout << "Generating array...";
    Sleep(1000);
    
    while (true)
    {
        system("cls");
        gotoxy(15, 3);
        cout << "========================================";
        gotoxy(15, 4);
        cout << "    SELECT ALGORITHM TO VISUALIZE";
        gotoxy(15, 5);
        cout << "========================================";
        
        gotoxy(15, 7);
        cout << "Current Array: [ ";
        for (int i = 0; i < size; i++)
        {
            cout << originalArr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << " ]";
        
        gotoxy(15, 9);
        cout << "1. Bubble Sort";
        gotoxy(15, 10);
        cout << "2. Insertion Sort";
        gotoxy(15, 11);
        cout << "3. Selection Sort";
        gotoxy(15, 12);
        cout << "4. Merge Sort";
        gotoxy(15, 13);
        cout << "5. Quick Sort";
        gotoxy(15, 14);
        cout << "6. Back to Main Menu";
        gotoxy(15, 16);
        cout << "Enter your choice (1-6): ";
        
        int choice;
        cin >> choice;
        
        if (choice == 6)
        {
            break;
        }
        
        if (choice < 1 || choice > 6)
        {
            gotoxy(15, 18);
            cout << RED << "Invalid choice!" << RESET;
            Sleep(2000);
            continue;
        }
        
        // Create a copy of original array for sorting
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = originalArr[i];
        }
        
        system("cls");
        gotoxy(15, 6);
        cout << "Initial Array: [ ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << " ]";
        
        gotoxy(15, 8);
        cout << "Press any key to start visualization...";
        getch();
        
        system("cls");
        
        switch(choice)
        {
            case 1:
                bubbleSortVisualize(arr, size);
                break;
            case 2:
                insertionSortVisualize(arr, size);
                break;
            case 3:
                selectionSortVisualize(arr, size);
                break;
            case 4:
                mergeSortVisualize(arr, size);
                break;
            case 5:
                quickSortVisualize(arr, size);
                break;
        }
        
        gotoxy(15, 30);
        cout << GREEN << "Visualization completed!" << RESET;
        gotoxy(15, 31);
        cout << "Press any key to continue...";
        getch();
    }
}

int main()
{
    while (true)
    {
        system("cls");
        gotoxy(15, 3);
        cout << BLUE << "========================================" << RESET;
        gotoxy(15, 4);
        cout << BLUE << "   SORTING ALGORITHM VISUALIZER" << RESET;
        gotoxy(15, 5);
        cout << BLUE << "========================================" << RESET;
        
        gotoxy(15, 7);
        cout << "1. Sort Data";
        gotoxy(15, 8);
        cout << "2. Visualize Sorting Algorithm";
        gotoxy(15, 9);
        cout << "3. Exit";
        
        gotoxy(15, 11);
        cout << "Enter your choice (1-3): ";
        
        int choice;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                sortDataMenu();
                break;
            case 2:
                visualizeSortingMenu();
                break;
            case 3:
                system("cls");
                gotoxy(15, 10);
                cout << GREEN << "Thank you for using the program!" << RESET;
                gotoxy(15, 11);
                cout << "Exiting...";
                Sleep(2000);
                return 0;
            default:
                gotoxy(15, 13);
                cout << RED << "Invalid choice! Please try again." << RESET;
                Sleep(2000);
        }
    }
    
    return 0;
}