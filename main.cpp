/*
 * AndroFree
 * by Navin Chandniya
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void listPkg(int x);
string getPkg(int x);
void searchPkg();
void disablePkg();
void uninstallPkg();
string getVendor();
void disableBloat();
void uninstallBloat();

int main()
{
    int choice;
    cout << "Fetching installed packages on your android device, please be patient...";
    system("adb shell \"pm list packages | sort\" > .\\allPackages.txt");
    system("adb shell \"pm list packages -3 | sort\" > .\\3rdPartyPackages.txt");
    system("cls");
    ifstream pkgFile;
    pkgFile.open("allPackages.txt");
    if(pkgFile.peek()==EOF) {
        pkgFile.close();
        cout << "\nNo ADB connections detected, exiting...\n";
        return 0;
    }
    while(1)
    {
        cout << "\n\n\tANDROID DEBLOATER\t";
        cout << "\n\n1. List all packages installed.";
        cout << "\n\n2. List all third-party packages installed.";
        cout << "\n\n3. List all safe-to-remove packages.";
        cout << "\n\n4. Search a package.";
        cout << "\n\n5. Disable a package.";
        cout << "\n\n6. Uninstall a package.";
        cout << "\n\n7. Disable recommended bloatware.";
        cout << "\n\n8. Uninstall recommended bloatware.";
        cout << "\n\n9. Exit.";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            listPkg(1);
            break;
        case 2:
            listPkg(2);
            break;
        case 3:
            listPkg(3);
            break;
        case 4:
            searchPkg();
            break;
        case 5:
            cout << "\nProcees with caution, removing core packages could break the system.";
            cout << "\nTry the 3rd option to check safe-to-remove packages for your device.";
            disablePkg();
            break;
        case 6:
            cout << "\nProcees with caution, removing core packages could break the system.";
            cout << "\nTry the 3rd option to check safe-to-remove packages for your device.";
            uninstallPkg();
            break;
        case 7:
            disableBloat();
            break;
        case 8:
            uninstallBloat();
            break;
        case 9:
            return 0;
        default:
            cout << "\nInvalid input, exiting...\n";
            return 0;
        }
    }
    return 0;
}

void listPkg(int x)
{
    string pkg;
    ifstream pkgFile;
    if (x == 1)
        pkgFile.open("allPackages.txt");
    else if (x==2)
        pkgFile.open("3rdPartyPackages.txt");
    else if (x==3)
        pkgFile.open(getVendor());
    system("cls");
    while (pkgFile)
    {
        getline(pkgFile, pkg);
        cout << pkg << '\n';
    }
    pkgFile.close();
}

string getPkg(int x)
{
    string pkg;
    if (x == 3)
        cout << "\n\nEnter string to search: ";
    else
        cout << "\n\nEnter package name: ";
    getchar(); // clear out stdin
    getline(cin, pkg);
    return pkg;
}

void searchPkg()
{
    string cmd = "adb shell \"pm list packages | grep ";
    cmd += getPkg(3) + "\"";
    system(cmd.c_str());
}

void disablePkg()
{
    string cmd = "adb shell pm disable-user --user 0 ";
    cmd += getPkg(4);
    system(cmd.c_str());
}

void uninstallPkg()
{
    string cmd = "adb shell pm uninstall -k --user 0 ";
    cmd += getPkg(5);
    system(cmd.c_str());
}

string getVendor()
{
    int vendorNum;
    string vendor;
    cout << "\n\n1. Samsung";
    cout << "\n\n2. Oppo";
    cout << "\n\n3. Oneplus";
    cout << "\n\n4. Realme";
    cout << "\n\n5. Xiaomi";
    cout << "\n\n6. Redmi";
    cout << "\n\n7. Poco";
    cout << "\n\n8. Vivo";
    cout << "\n\n9. Iqoo";
    cout << "\n\nEnter your android device vendor (int): ";
    cin >> vendorNum;
    switch (vendorNum)
    {
    case 1:
        vendor = "samsung.txt";
        break;
    case 2:
    case 3:
    case 4:
        vendor = "oppo.txt";
        break;
    case 5:
    case 6:
    case 7:
        vendor = "xiaomi.txt";
        break;
    case 8:
    case 9:
        cout << "-> Removes touchpal keyboard if installed, make sure you have an alternate keyboad installed.";
        vendor = "vivo.txt";
        break;
    }
    return vendor;
}

void disableBloat()
{
    string pkg, cmd;
    ifstream vendorFile;
    vendorFile.open(getVendor());
    while (vendorFile)
    {
        getline(vendorFile, pkg);
        cmd = "adb shell pm disable-user --user 0 " + pkg;
        system(cmd.c_str());
    }
    vendorFile.close();
}

void uninstallBloat()
{
    string pkg, cmd;
    ifstream vendorFile;
    vendorFile.open(getVendor());
    while (vendorFile)
    {
        getline(vendorFile, pkg);
        cmd = "adb shell pm unsintall -k --user 0 " + pkg;
        system(cmd.c_str());
    }
    vendorFile.close();
}