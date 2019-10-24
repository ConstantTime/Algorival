class matrix
{
public:
        vector<vector<ll> > M;
        ll nn , mm;
        matrix()
        {
                nn = mm = 0;
        }
        matrix(ll R , ll C)
        {
                nn = R;
                mm = C;
                M.resize(R);
                for(ll i = 0 ; i < R ; i++)
                {
                        M[i].resize(C);
                }
        }
        void fills(ll i , ll j , ll val)
        {
                M[i][j] = val;
        }
        void equate(matrix B)
        {
                M.clear();
                nn = B.nn;
                mm = B.mm;
                M = B.M;
        }
        matrix operator* (matrix B)
        {
                assert(mm == B.nn);
                matrix ret(nn , B.mm);
                for(ll i = 0 ; i < nn ; i++) for(ll j =0 ; j < B.mm ; j++) ret.M[i][j] = 0;
                        for(ll i=0;i<nn;i++)
                        {
                                for(ll j=0;j<B.mm;j++)
                                {
                                        for(ll k=0;k<mm;k++)
                                        {
                                                ret.M[i][j] += M[i][k] * B.M[k][j];
                                                ret.M[i][j] %= MOD;
                                        }
                                }
                        }
                        return ret;
        }
        matrix EXP(ll x){
                assert(nn == mm);
                matrix A(nn , mm);
                for(ll i = 0 ; i < nn ; i++){
                        for(ll j = 0; j < mm ; j++)
                                A.M[i][j] = M[i][j];
                }
                matrix ret(nn , nn);
                for(ll i = 0 ; i < nn ; i++) {
                                ret.M[i][i] = 1;
                }
                while(x){
                        if(x&1){
                                ret.equate(ret*A);
                        }
                        A.equate(A*A);
                        x = x / 2;
                }
                return ret;
        }
};