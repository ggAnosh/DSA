#include <iostream>
using namespace std;
int choice, aSize;
int **arr, *pSize, totalArray = 0;

void printArray()
{
  for (int i = 0; i < totalArray; ++i)
  {
    cout << "Element of array " << i + 1 << endl;
    for (int j = 0; j < pSize[i]; ++j)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void checkRepated()
{
  // Loop over all arrays
  for (int i = 0; i < totalArray; ++i)
  {
    int newSize = pSize[i]; // Keep track of the new size

    // Traverse each element in the array
    for (int j = 0; j < newSize; ++j)
    {
      // Check for duplicates after the current element
      for (int k = j + 1; k < newSize; ++k)
      {
        // If a duplicate is found
        if (arr[i][j] == arr[i][k])
        {
          // Shift all elements after the duplicate to the left
          for (int l = k; l < newSize - 1; ++l)
          {
            arr[i][l] = arr[i][l + 1];
          }

          // Decrease the new size
          newSize--;
          k--; // Recheck the current index as it might now contain a duplicate
        }
      }
    }

    // After removing duplicates, update the size of the array
    pSize[i] = newSize;
  }
}

void getData()
{
  cout << "Enter how many arrays do you want to create?" << endl;
  cin >> choice;

  if (choice > 0)
  {

    arr = new int *[choice];
    pSize = new int[choice];

    for (int i = 0; i < choice; ++i)
    {
      cout << "Enter the size for array " << i + 1 << ": ";
      cin >> aSize;

      arr[i] = new int[aSize];
      pSize[i] = aSize;

      cout << "Enter the elements for array " << i + 1 << ": " << endl;
      for (int j = 0; j < aSize; ++j)
      {
        cin >> arr[i][j];
      }
      // Call checkRepated to remove duplicates after data entry
      checkRepated();
    }
    totalArray = choice;
  }
  else
  {
    cout << "Enter a valid numebr starting from 1." << endl;
  }
}

void deleteElement()
{
  int arrIndex, arrValue;

  cout << "The array has the following values: " << endl;
  printArray();

  cout << "Enter which array do you want to do the delete command. " << endl;
  cin >> arrIndex;
  --arrIndex;

  if (arrIndex > 0 && arrIndex < totalArray)
  {

    cout << "Enter which value you want to delete of the array." << endl;
    cin >> arrValue;

    bool found = false;

    for (int i = 0; i < pSize[arrIndex]; ++i)
    {
      if (arr[arrIndex][i] == arrValue)
      {
        found = true;
        break;
      }
    }

    if (found)
    {

      cout << "Before deleting: " << endl;

      for (int i = 0; i < pSize[arrIndex]; ++i)
      {
        cout << arr[arrIndex][i] << " ";
      }
      cout << endl;

      for (int i = 0; i < pSize[arrIndex]; ++i)
      {
        if (arr[arrIndex][i] == arrValue)
        {
          for (int j = i; j < pSize[arrIndex] - 1; ++j)
          {
            int temp = arr[arrIndex][j];
            arr[arrIndex][j] = arr[arrIndex][j + 1];
            arr[arrIndex][j + 1] = temp;
          }
        }
      }

      pSize[arrIndex]--;

      cout << "After deleting the element: " << endl;

      for (int i = 0; i < pSize[arrIndex]; ++i)
      {
        cout << arr[arrIndex][i] << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "The element is not present in the array." << endl;
    }
  }
  else
  {
    cout << "There is no such array that you are prefering." << endl;
  }
}

void sortArray()
{
  cout << "Sorting in ascending order " << endl;

  for (int i = 0; i < choice; ++i)
  {
    for (int j = 0; j < pSize[i]; ++j)
    {
      for (int k = j + 1; k < pSize[i]; ++k)
      {
        if (arr[i][j] > arr[i][k])
        {
          int temp = arr[i][k];
          arr[i][k] = arr[i][j];
          arr[i][j] = temp;
        }
      }
    }
  }

  printArray();

  cout << "Sorting in descending order " << endl;

  for (int i = 0; i < choice; ++i)
  {
    for (int j = 0; j < pSize[i]; ++j)
    {
      for (int k = j + 1; k < pSize[i]; ++k)
      {
        if (arr[i][j] < arr[i][k])
        {
          int temp = arr[i][k];
          arr[i][k] = arr[i][j];
          arr[i][j] = temp;
        }
      }
    }
  }
  printArray();
}

void mergeArray()
{
  cout << "The array we have: " << endl;
  printArray();

  cout << "Enter the two arrays you want to merge." << endl;

  int arrIndex[2];

  for (int i = 0; i < 2; ++i)
  {
    cin >> arrIndex[i];
  }

  int firstArray = arrIndex[0] - 1;
  int secArray = arrIndex[1] - 1;

  arr[totalArray] = new int[pSize[firstArray] + pSize[secArray]];
  pSize[totalArray] = pSize[firstArray] + pSize[secArray];

  for (int i = 0; i < pSize[firstArray]; ++i)
  {
    arr[totalArray][i] = arr[firstArray][i];
  }

  for (int i = 0; i < pSize[secArray]; ++i)
  {
    arr[totalArray][pSize[firstArray] + i] = arr[secArray][i];
  }

  checkRepated();

  cout << "After merging the array: " << endl;

  for (int i = 0; i < pSize[totalArray]; ++i)
  {
    cout << arr[totalArray][i] << " ";
  }
  cout << endl;

  ++totalArray;
}

int main()
{
  char choice;

  string ch = "A";

  while (ch == "A")
  {
    cout << "Enter your choice:" << endl;
    cout << "A. Enter any element in the array." << endl;
    cout << "B. Delete any element in the array." << endl;
    cout << "C. Sort the array." << endl;
    cout << "D. Display elements of the array." << endl;
    cout << "E. Merge an array." << endl;

    cin >> choice;

    switch (choice)
    {
    case 'A':
      getData();
      break;

    case 'B':
      deleteElement();
      break;

    case 'C':
      sortArray();
      break;

    case 'D':
      printArray();
      break;

    case 'E':
      mergeArray();
      break;
    }

    cout << "Do you want to do more?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cin >> ch;
  }

  for (int i = 0; i < choice; ++i)
  {
    delete[] arr[i];
  }

  delete[] arr;
  delete[] pSize;

  return 0;
}
