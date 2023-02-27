#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

bool isPrime(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            ++count;
        }
    }
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    // Get input from  tc1_input
    ifstream infile;
    infile.open("tc1_input");
    infile >> HP;          //[1,999]
    infile >> level;       //[1,10]
    infile >> remedy;      //
    infile >> maidenkiss;  // [1,99]
    infile >> phoenixdown; //
    rescue = -1;
    const int maxHP = HP;
    string eventData, pack;
    // Đọc eventData
    infile.seekg(1, ios_base::cur);
    getline(infile, eventData);
    // Đọc tc1_pack
    infile.seekg(0, ios_base::cur);
    getline(infile, pack);
    //
    //
    string temp = "";    // Đọc qua từng sự kiện một
    int event_index = 0; // Lưu trữ số thứ tự của sự kiện
    bool Arthur, Lancelot;
    if (HP == 999) // Đây là vua Arthur
    {
        Arthur = true;
    }
    if (isPrime(HP)) // Đây là Lancelot
    {
        Lancelot = true;
    }
    for (int i = 0; i < eventData.length(); i++) // Thực thi các sự kiện
    {
        temp += eventData[i];
        if (temp == " ")
        {
            temp = "";
        }
        if ((eventData[i + 1] == ' ') || (eventData[i + 1] == '\0')) // Đã có số của sự kiện
        {
            ++event_index;
            if (temp == "0") // Bowser đầu hàng và trả lại công chúa
            {
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                exit(0);
            }
            if (temp == "1") // Gặp MadBear
            {
                int levelO; // Level của quái
                int b = event_index % 10;
                levelO = (event_index > 6) ? ((b > 5) ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level < 10)
                    {
                        ++level;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if ((level == levelO))
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level < levelO)
                {
                    double damage = 1.0 * levelO * 10;
                    HP -= int(damage);
                    if ((HP <= 0) && (phoenixdown == 0))
                    {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        exit(0);
                    }
                    else if ((HP <= 0) && (phoenixdown > 0))
                    {
                        HP = maxHP;
                        --phoenixdown;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }
            if (temp == "2") // Gặp Bandit
            {
                int levelO; // Level của quái
                int b = event_index % 10;
                levelO = (event_index > 6) ? ((b > 5) ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level < 10)
                    {
                        ++level;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if ((level == levelO))
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level < levelO)
                {
                    double damage = 1.5 * levelO * 10;
                    HP -= int(damage);
                    if ((HP <= 0) && (phoenixdown == 0))
                    {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        exit(0);
                    }
                    else if ((HP <= 0) && (phoenixdown > 0))
                    {
                        HP = maxHP;
                        --phoenixdown;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }
            if (temp == "3") // Gặp LordLupin
            {
                int levelO; // Level của quái
                int b = event_index % 10;
                levelO = (event_index > 6) ? ((b > 5) ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level < 10)
                    {
                        ++level;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if ((level == levelO))
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level < levelO)
                {
                    double damage = 4.5 * levelO * 10;
                    HP -= int(damage);
                    if ((HP <= 0) && (phoenixdown == 0))
                    {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        exit(0);
                    }
                    else if ((HP <= 0) && (phoenixdown > 0))
                    {
                        HP = maxHP;
                        --phoenixdown;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }
            if (temp == "4") // Gặp Elf
            {
                int levelO; // Level của quái
                int b = event_index % 10;
                levelO = (event_index > 6) ? ((b > 5) ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level < 10)
                    {
                        ++level;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if ((level == levelO))
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level < levelO)
                {
                    double damage = 7.5 * levelO * 10;
                    HP -= int(damage);
                    if ((HP <= 0) && (phoenixdown == 0))
                    {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        exit(0);
                    }
                    else if ((HP <= 0) && (phoenixdown > 0))
                    {
                        HP = maxHP;
                        --phoenixdown;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }
            if (temp == "5") // Gặp Troll
            {
                int levelO; // Level của quái
                int b = event_index % 10;
                levelO = (event_index > 6) ? ((b > 5) ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level < 10)
                    {
                        ++level;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if ((level == levelO))
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level < levelO)
                {
                    double damage = 9.5 * levelO * 10;
                    HP -= int(damage);
                    if ((HP <= 0) && (phoenixdown == 0))
                    {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        exit(0);
                    }
                    else if ((HP <= 0) && (phoenixdown > 0))
                    {
                        HP = maxHP;
                        --phoenixdown;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }
            if (temp == "6") // Gặp phù thủy Saman
            {
                int levelO; // Level của quái
                int b = (i + 1) % 10;
                levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level <= 8)
                    {
                        level += 2;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else if ((level == levelO))
                    {
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else
                    {
                        // Hóa tí hon trong 3 sự kiện tiếp theo
                    }
                }
            }
            if (temp == "7") // Gặp Siren Vajsh
            {
                int levelO; // Level của quái
                int b = (i + 1) % 10;
                levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
                if ((level > levelO) || (Arthur == true) || (Lancelot == true))
                {
                    if (level <= 8)
                    {
                        level += 2;
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else if ((level == levelO))
                    {
                        rescue = -1;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else
                    {
                        // Hóa ếch trong 3 sự kiện tiếp theo
                    }
                }
            }
            if (temp == "11") // Nhặt được nấm tăng lực MushMario
            {
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                int s1 = 0, j = 0, max2digit = 99; // Calculate s1;
                while (j < n1)
                {
                    s1 += max2digit;
                    max2digit -= 2;
                    ++j;
                }
                HP = HP + (s1 % 100);
                if (!isPrime(HP))
                {
                    int k = 1;
                    while (!isPrime(HP + k))
                    {
                        ++k;
                    }
                    HP = HP + k;
                }
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                rescue = -1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            if (temp == "12") // Nhặt được nấm Fibonacci MushFibo
            {
                if (HP == 1)
                {
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    // Tạo dãy Fibonacci
                    int fibo[16];
                    fibo[0] = 1;
                    fibo[1] = 1;
                    for (int i = 2; i < 16; i++)
                    {
                        fibo[i] = fibo[i - 1] + fibo[i - 2];
                    }
                    // Chuyển HP về số Fibonacci gần nhất
                    int hieu[16];
                    for (int i = 0; i < 16; i++)
                    {
                        hieu[i] = abs(HP - fibo[i]);
                    }
                    int min = hieu[0];
                    int min_index;
                    for (int i = 1; i < 16; i++)
                    {
                        if (hieu[i] < min)
                        {
                            min = hieu[i];
                            min_index = i;
                        }
                    }
                    HP = fibo[min_index];
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
            if ((temp[0] == '1') && (temp[1] == '3')) // Event 13, ví dụ 1312312321312
            {
                // Đọc dữ liệu từ file_mush_ghost
                infile.open("tc1_mush_ghost");
                string n2, tempOfMushGhost;
                infile >> n2;
                infile.seekg(1, ios_base::cur);
                getline(infile, tempOfMushGhost);
                // Chuyển dãy số từ string sang int
                int mushGhost_Int[stoi(n2)];
                int mushGhost_int_index = 0; // Số phần tử của mảng mushGhost_int
                string temp_ghost;
                for (int j = 0; j < tempOfMushGhost.length(); j++)
                {
                    temp_ghost += tempOfMushGhost[i];
                    if (temp_ghost == ",")
                    {
                        temp_ghost = "";
                    }
                    if ((tempOfMushGhost[j + 1] == ',') || (tempOfMushGhost[j + 1] == '\0'))
                    {
                        mushGhost_Int[mushGhost_int_index] = stoi(temp_ghost);
                        ++mushGhost_int_index;
                        temp_ghost = "";
                    }
                }
                // Xét gặp nấm ma loại nào. Có 4 loại ứng với 4 mã là 1,2,3,4
                for (int j = 2; j < temp.length(); j++)
                {
                    if (temp[j] == '1') // Gặp nấm ma loại 1
                    {
                        // Tìm vị trị cuối cùng (last_index) cho Max và Min của mushGhost_int
                        int min = mushGhost_Int[0];
                        int max = mushGhost_Int[0];
                        for (int k = 1; k < mushGhost_int_index; k++)
                        {
                            if (mushGhost_Int[k] < min)
                            {
                                min = mushGhost_Int[k];
                            }
                            if (mushGhost_Int[k] > max)
                            {
                                max = mushGhost_Int[k];
                            }
                        }
                        int maxi, mini;
                        for (int k = mushGhost_int_index - 1; k >= 0; k--)
                        {
                            if (mushGhost_Int[k] == max)
                            {
                                maxi = k;
                                break;
                            }
                        }
                        for (int k = mushGhost_int_index - 1; k >= 0; k--)
                        {
                            if (mushGhost_Int[k] == min)
                            {
                                mini = k;
                                break;
                            }
                        }
                        /////////////////////////////
                        HP = HP - (maxi + mini);
                    }
                    if (temp[j] == '2') // Gặp nấm ma loại 2
                    {
                        // Kiểm tra dãy số có hình dạng dãy núi hay không
                        int mtx, mti;
                        int max_index;
                        int max = mushGhost_Int[0];
                        for (int k = 1; k < mushGhost_int_index; k++) // Tìm max của dãy
                        {
                            if (mushGhost_Int[k] > max)
                            {
                                max = mushGhost_Int[k];
                                max_index = k;
                            }
                        }
                        // Kiểm tra tính tăng dần
                        bool increasing = true;
                        for (int k = 0; k < max_index; k++)
                        {
                            if (mushGhost_Int[k + 1] < mushGhost_Int[k])
                            {
                                increasing = false;
                            }
                        }
                        // Kiểm tra tính giảm dần
                        bool decreasing = true;
                        for (int k = max_index; k < mushGhost_int_index - 1; k++)
                        {
                            if (mushGhost_Int[k + 1] > mushGhost_Int[k])
                            {
                                decreasing = false;
                            }
                        }
                        ////////////
                        if (increasing && decreasing)
                        {
                            mtx = max;
                            mti = max_index;
                        }
                        else
                        {
                            mtx = -2;
                            mti = -3;
                        }
                        HP = HP = (mtx + mti);
                    }
                    if (temp[j] == '3') // Gặp nấm ma loại 3
                    {
                        for (int k = 0; k < mushGhost_int_index; k++)
                        {
                            if (mushGhost_Int[k] < 0)
                            {
                                mushGhost_Int[k] = -mushGhost_Int[k];
                            }
                            mushGhost_Int[k] = (17 * mushGhost_Int[k] + 9) % 257;
                        }
                        int min = mushGhost_Int[0];
                        int max = mushGhost_Int[0];
                        for (int k = 1; k < mushGhost_int_index; k++)
                        {
                            if (mushGhost_Int[k] < min)
                            {
                                min = mushGhost_Int[k];
                            }
                            if (mushGhost_Int[k] > max)
                            {
                                max = mushGhost_Int[k];
                            }
                        }
                        int maxi2, mini2;
                        for (int k = mushGhost_int_index - 1; k >= 0; k--)
                        {
                            if (mushGhost_Int[k] == max)
                            {
                                maxi2 = k;
                                break;
                            }
                        }
                        for (int k = mushGhost_int_index - 1; k >= 0; k--)
                        {
                            if (mushGhost_Int[k] == min)
                            {
                                mini2 = k;
                                break;
                            }
                        }
                        HP = HP - (maxi2 + mini2);
                    }
                    if (temp[j] == '4') // Gặp nấm ma loại 4
                    {
                        for (int k = 0; k < mushGhost_int_index; k++)
                        {
                            if (mushGhost_Int[k] < 0)
                            {
                                mushGhost_Int[k] = -mushGhost_Int[k];
                            }
                            mushGhost_Int[k] = (17 * mushGhost_Int[k] + 9) % 257;
                        }
                        int max = mushGhost_Int[0];
                        for (int k = 1; k < mushGhost_int_index; k++)
                        {
                            if (mushGhost_Int[k] > max)
                            {
                                max = mushGhost_Int[k];
                            }
                        }
                        // Tìm số lớn thứ hai trong mảng
                        bool find_max_3x = false;
                        int max2_3x = mushGhost_Int[0];
                        int max2_3i;
                        for (int i = 1; i < mushGhost_int_index; i++)
                        {
                            if ((max2_3x < max) && (max2_3x < mushGhost_Int[i]) && (mushGhost_Int[i] != max))
                            {
                                max2_3x = mushGhost_Int[i];
                                find_max_3x = true;
                            }
                        }
                        if (find_max_3x)
                        {
                            // Tìm vị trí đầu tiên xuất hiện của max2_3x

                            for (int k = 0; k < mushGhost_int_index; k++)
                            {
                                if (mushGhost_Int[k] == max2_3x)
                                {
                                    max2_3i = k;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            max2_3x = -5;
                            max2_3i = -7;
                        }
                        HP = HP - (max2_3x + max2_3i);
                    }

                    if (HP < 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            --phoenixdown;
                            rescue = -1;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                        else // Hết phoenixdown
                        {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            exit(0);
                        }
                    }
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
            if (temp == "15") // Nhặt được Remedy
            {
                ++remedy;
                rescue = -1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            if (temp == "16") // Nhặt được MaidenKiss
            {
                ++maidenkiss;
                rescue = -1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            if (temp == "17") // Nhặt được PhoenixDown
            {
                ++phoenixdown;
                rescue = -1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            if (temp == "18") // Gặp phù thủy Merlin
            {
                int count_merlin = 0;
                if (count_merlin < 1)
                {
                    // Thông tin nằm trong file_merlin_pack //
                    // Đọc file_merlin_pack
                    ifstream infile;
                    infile.open("tc1_merlin_pack");
                    string n9, str;
                    infile >> n9;         // Chứa số nguyên dương n9
                    while (!infile.eof()) // Đọc từng dòng trong n9 dòng kế tiếp trong file
                    {
                        getline(infile, str); // Đã có từng dòng
                        if (str == "merlin" || str == "Merlin")
                        {
                            if (HP + 3 <= maxHP)
                            {
                                HP += 3;
                                rescue = -1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            else
                            {
                                HP = maxHP;
                                rescue = -1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            continue;
                        }
                        else
                        {
                            // Chuyển tất cả về chữ thường
                            for (int i = 0; i < str.length(); i++)
                            {
                                if (str[i] >= 65 && str[i] <= 90) // ASCII 65-90 là cho chữ in hoa
                                {
                                    str[i] += 32;
                                }
                            }
                            // Tìm chuỗi "merlin" trong từng str
                            size_t found = str.find("merlin");
                            if (found != string::npos) // Tìm thấy chuỗi "merlin"
                            {
                                if (HP + 2 <= maxHP)
                                {
                                    HP += 2;
                                    rescue = -1;
                                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                }
                                else
                                {
                                    HP = maxHP;
                                    rescue = -1;
                                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                }
                            }
                        }
                    }
                    ++count_merlin;
                }
            }
            if (temp == "19") // Gặp thần thuốc Asclepius
            {
                int count_Aclepius = 0;
                if (count_Aclepius < 1)
                {
                    // Thông tin nằm trong file_asclepius_pack //
                    // Đọc file_aclepius_pack
                    infile.open("tc1_aclepius_pack");
                    string r1, c1, str = "", temp = "";
                    infile >> r1;
                    infile >> c1;

                    int arr[stoi(r1)][stoi(c1)]; // Mảng 2 chiều có r1 hàng và c1 cột
                    int r1_index = 0;
                    int c1_index = 0;
                    getline(infile, str); // Đọc dòng trắng ở đầu file (?)
                    while (!infile.eof())
                    {
                        getline(infile, str); // Đã có str
                        for (int i = 0; i < str.length(); i++)
                        {
                            temp += str[i];
                            if (temp == " ")
                            {
                                temp = "";
                            }
                            if ((str[i + 1] == ' ') || (str[i + 1] == '\0'))
                            {
                                arr[r1_index][c1_index] = stoi(temp);
                                ++c1_index;
                                temp = "";
                            }
                        }
                        ++r1_index;
                        c1_index = 0;
                        str = "";
                    }
                    // Đã có mảng số liệu
                    // Nhặt thuốc
                    for (int i = 0; i < stoi(r1); i++)
                    {
                        int count = 0;
                        c1_index = 0;
                        while ((count < 3) && (c1_index < stoi(c1))) // Nhặt tối đa 3 thuốc trên một dòng
                        {
                            if (arr[i][c1_index] == 16) // Nhặt được remedy
                            {
                                ++remedy;
                                rescue = -1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                ++count;
                            }
                            if (arr[i][c1_index] == 17) // Nhặt được maidenkiss
                            {
                                ++maidenkiss;
                                rescue = -1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                ++count;
                            }
                            if (arr[i][c1_index] == 18) // Nhặt được phoenixdown
                            {
                                ++phoenixdown;
                                rescue = -1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                ++count;
                            }
                            ++c1_index;
                        }
                    }
                    ++count_Aclepius;
                }
            }
            if (temp == "99") // Gặp Browser
            {
                if ((Arthur == true) || ((Lancelot == true) && (level >= 8)) || (level == 10))
                {
                    level = 10;
                    rescue = -1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    exit(0);
                }
            }
            temp = "";
        }
    }
}