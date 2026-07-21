class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bitrep(32, 0);
        for(int i=31;i>=0;i--){
            bitrep[i] = n%2;
            n = n/2;
        }

        uint32_t k = 0, twos = 1;
        for(int i=0;i<32;i++){
            k = k + twos*bitrep[i];
            twos *= 2;
        }

        return k;
    }
};
