using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer;
    long long W = w, H = h;
    long long total = W * H;
    long long gcdn = gcd(W,H);
    long long ww = W / gcdn, hh = H / gcdn;
    answer = total - (gcdn * (ww+hh-1));
    
    return answer;
}