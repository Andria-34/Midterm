// სტრიქონში ა სიმბოლოების დათვლის კოდი

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string str1 = "eka rochikashvili";
int indexi, raodenoba = 0;
for (indexi = 0; indexi < str1.length(); indexi++)
if (str1[indexi] == 'a') raodenoba++;
cout << "a simbolos raodenoba = " << raodenoba << endl;
    
   
    return 0;}

// სტრიქონში ციფრების დათვლის კოდი

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{string str1 = "a1b2bc34de8ot6r";
int indexi, raodenoba = 0;
for (indexi = 0; indexi < str1.length(); indexi++)
if (str1[indexi] >= '0' && str1[indexi] <= '9') raodenoba++;
cout << "cifrebis raodenoba = " << raodenoba << endl;
   
    return 0;}

// სტრიქონში e სიმბოლოების i სიმბოლით შეცვლა

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{string str1 = "shevcvaloT simboloebi";
int indexi, raodenoba = 0;
cout << "sawyisi striqoni - " << str1 << endl;
for (indexi = 0; indexi < str1.length(); indexi++)
if (str1[indexi] == 'e') str1[indexi] = 'i';
cout << "shecvili striqoni - " << str1 << endl;
   
    return 0;}

// დათვლის k სიმბოლოს პირველ პოზიციას

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{string str1 = "eka rotchikashvili";
int indexi;
indexi = str1.find('k');
cout << "k simbolos pozicia = " << indexi+1 << endl;
    return 0;}

// უსჯ და უსგ საპოვნელად 

#include <iostream>
using namespace std;

// ფუნქცია უსგ-ს საპოვნელად
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ფუნქცია უსჯ-ს საპოვნელად
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;

    int result = lcm(num1, num2);

    cout << "LCM of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}

// დავალება 1

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>

using namespace std;

int main() {
    // Initialize the array A with random numbers in the specified range
    const int N = 10;
    vector<int> A(N);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-10, 20);

    for (int i = 0; i < N; ++i) {
        A[i] = dist(gen);
    }

    // Calculate the maximum value at odd indices
    int maxOdd = A[1];
    for (int i = 3; i < N; i += 2) {
        maxOdd = max(maxOdd, A[i]);
    }

    // Calculate the minimum value at even indices
    int minEven = A[0];
    for (int i = 2; i < N; i += 2) {
        minEven = min(minEven, A[i]);
    }

    // Compute GCD and LCM
    int gcdValue = gcd(maxOdd, minEven);
    int lcmValue = lcm(maxOdd, minEven);

    // Replace the maximum value at odd index with GCD
    A[1] = gcdValue;

    // Print the resulting array
    cout << "Original array A: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Maximum value at odd index: " << maxOdd << endl;
    cout << "Minimum value at even index: " << minEven << endl;
    cout << "GCD: " << gcdValue << endl;
    cout << "LCM: " << lcmValue << endl;

    cout << "Modified array A: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// დავალება 2

#include <iostream>
using namespace std;

int main() {
    // Initialize an array to store the count of numbers with a specific sum
    int first[28] = {0}; // For the first three digits
    int second[28] = {0}; // For the last three digits

    // Compute the count for the first three digits
    for (int s = 0; s <= 18; ++s) {
        int c = 10 - (s < 9 ? (9 - s) : (s - 9));
        for (int d = 1; d <= 9; ++d) {
            first[s + d] += c;
        }
    }

    // Compute the count for the last three digits (similar to the first part)
    for (int s = 0; s <= 18; ++s) {
        int c = 10 - (s < 9 ? (9 - s) : (s - 9));
        for (int d = 0; d <= 9; ++d) {
            second[s + d] += c;
        }
    }

    // Calculate the total count of six-digit numbers
    long long total_count = 0;
    for (int i = 1; i <= 27; ++i) {
        total_count += static_cast<long long>(first[i]) * second[i];
    }

    cout << "Total count of six-digit numbers: " << total_count << endl;

    return 0;
}

