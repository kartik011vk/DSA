class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int am = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int ad = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');

        int lm = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        int ld = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

        int bm = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        int bd = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');

        int rm = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        int rd = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

        int a1 = ad, a2 = ld, b1 = bd, b2 = rd;

        for (int i = 0; i < am - 1; i++)
            a1 += days[i];

        for (int i = 0; i < lm - 1; i++)
            a2 += days[i];

        for (int i = 0; i < bm - 1; i++)
            b1 += days[i];

        for (int i = 0; i < rm - 1; i++)
            b2 += days[i];

        int start;

        if (a1 > b1)
            start = a1;
        else
            start = b1;

        int end;

        if (a2 < b2)
            end = a2;
        else
            end = b2;

        if (start > end)
            return 0;
        else
            return end - start + 1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna