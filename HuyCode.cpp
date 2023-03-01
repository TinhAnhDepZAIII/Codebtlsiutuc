// GAP NAM MA
void MushGhost(string file_mush , int& HP, int eventcode, const int MAXHP , int& rescue , int& phoenixdown , bool& tihon) {
    int remainder;
    ifstream fs;
    fs.open(file_mush);
    int n2;
    fs >> n2;
    int arr[100];
    int i = 0;
    string linenum; 
    while (getline(fs, linenum, ',')) {
        int number = stoi(linenum);
        arr[i++] = number; 
    }
    int arrnum[100];
    int numar = 0;
    while (eventcode != 13) {
        remainder = eventcode % 10;
        eventcode = eventcode / 10;
        arrnum[numar++] = remainder;
    }
    for (int k = 0, j = numar - 1; k < j; k++, j--) {
        swap(arrnum[k], arrnum[j]);
    }
    int count4 = 0;
    while (count4 < numar) {
        // NAM MA LOAI 1
        if (arrnum[count4] == 1) {
            int maximum = arr[0];
            int minimum = arr[0];
            int maxi = 0;
            int mini = 0;
            for (int j = 0; j < n2; j++) {
                if (arr[j] >= maximum) { maximum = arr[j]; maxi = j; } // TIM MAXI
                if (arr[j] <= minimum) { minimum = arr[j]; mini = j; } // TIM MINI
            }
            HP = HP - (maxi + mini);
        }
        // NAM MA LOAI 2
        if (arrnum[count4] == 2) {
            int mtx = arr[0];
            int mti = 0;
            bool mount = true;
            if (n2 == 1) {
                mtx = arr[0];
                mti = 0;
                goto dis;
            }
            for (int i = 0; i < n2; i++) { // TIM DINH NUI
                if (arr[i] > mtx) {
                    mtx = arr[i];
                    mti = i;
                }
            }
            for (int j = 0; j < mti; j++) { // SUON BEN TRAI
                if (arr[j] < arr[j + 1]) {}
                else {
                    mtx = -2;
                    mti = -3;
                    mount = false;
                    break;
                }
            }
            if (mount) {
                for (int j = n2 - 1; j > mti; j--) { // SUON BEN PHAI
                    if (arr[j] < arr[j - 1]) {}
                    else {
                        mti = -3;
                        mtx = -2;
                        break;
                    }
                }
            }
        dis:  HP = HP - (mtx + mti);
        }
        // NAM MA LOAI 3
        if (arrnum[count4] == 3) {
            int c_arr[100];     // TAO HAM ARRAY PHU
            for (int j = 0; j < n2; j++) {
                c_arr[j] = arr[j];
            }
            for (int j = 0; j < n2; j++) { // THUC HIEN PHEP BIEN DOI VOI ARRAY PHU
                if (c_arr[j] < 0) {
                    c_arr[j] = -c_arr[j];
                }
                c_arr[j] = (17 * c_arr[j] + 9) % 257;
            }
            // HAM TIM MAXI2 , MINI2
            int maximum = c_arr[0];
            int minimum = c_arr[0];
            int maxi2 = 0;
            int mini2 = 0;
            for (int j = 0; j < n2; j++) { // TIM MAXI2
                if (c_arr[j] > maximum) {
                    maximum = c_arr[j];
                    maxi2 = j;
                }
                if (c_arr[j] < minimum) {  // TIM MINI2
                    minimum = c_arr[j];
                    mini2 = j;
                }
            }
            HP = HP - (maxi2 + mini2);
        }

        // NAM MA LOAI 4
        if (arrnum[count4] == 4) {
            int max2_3x, max2_3i;
            if (n2 < 3)
            {
                max2_3x = -5;
                max2_3i = -7;
                HP = HP - (max2_3x + max2_3i);
                continue;
            }
            int c_arr[100];     // TAO HAM ARRAY PHU
            for (int j = 0; j < n2; j++) {
                c_arr[j] = arr[j];
            }
            for (int j = 0; j < n2; j++) { // THUC HIEN PHEP BIEN DOI VOI ARRAY PHU
                if (c_arr[j] < 0) {
                    c_arr[j] = -c_arr[j];
                }
                c_arr[j] = (17 * c_arr[j] + 9) % 257;
            }
            int vitri0 = c_arr[0], vitri1 = c_arr[1], vitri2 = c_arr[2];
            // TIM SO LON THU HAI
            for (int k = 0; k < 3; k++)
                for (int j = 0; j < 3 - k - 1; j++)
                {
                    if (c_arr[j + 1] > c_arr[j])
                    {
                        int temp = c_arr[j + 1];
                        c_arr[j + 1] = c_arr[j];
                        c_arr[j] = temp;
                    }
                }
            if (c_arr[2] == c_arr[0])
            {
                max2_3x = -5;
                max2_3i = -7;
            }
            else if (c_arr[0] == c_arr[1])
            {
                max2_3x = c_arr[2];
            }
            else { max2_3x = c_arr[1]; }
            if (max2_3x == vitri0) { max2_3i = 0; }
            else if (max2_3x == vitri1) { max2_3i = 1; }
            else if (max2_3x == vitri2) { max2_3i = 2; }
            HP = HP - (max2_3x + max2_3i);
        }
        // HAM HOI` SINH
        if (HP <= 0) { HoiSinh(phoenixdown, HP, rescue, tihon, MAXHP); }
        //  HAM MAXHP
        if (HP > MAXHP) { HP = MAXHP; }
        if (rescue == 0) { break; }
        count4++;
    } 
}