package JCodes.LeetCode;

import JCodes.Trie.Trie;
import JCodes.generics.PairGenericWithComparator;

import java.util.*;

public class Solution {
    public static Vector< Integer > nextGreaterDistance(int[] T) {
        Vector < Integer > ans = new Vector<>();

        int n = T.length;

        if(n == 0) return ans;

        ans.setSize(n);

        Stack<PairGenericWithComparator.pair<Integer , Integer>> s = new Stack<>();
        PairGenericWithComparator.pair<Integer , Integer> temp;

        temp = new PairGenericWithComparator.pair<>(T[0] , 0);
        s.add(temp);

        for(int i = 1 ; i < n ; i++) {
            if(s.empty()) {
                temp = new PairGenericWithComparator.pair<>(T[i] , i);
                s.push(temp);
                continue;
            }

            while(s.empty() == false && s.peek().getFi() < T[i]) {
                ans.set(s.peek().getSe(),  i - s.peek().getSe());
                s.pop();
            }

            temp = new PairGenericWithComparator.pair<>(T[i] , i);
            s.push(temp);
        }

        while(s.empty() == false) {
            ans.set(s.peek().getSe() , 0);
            s.pop();
        }
        return ans;
    }

    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;

        int cnt = n / 3;

        int count1 = 0;
        int count2 = 0;

        List < Integer > ans = new ArrayList<>();

        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        for(int i = 0 ; i < n ; i++) {
            if(first == nums[i]) {
                count1++;
            }
            else if(second == nums[i]) {
                count2++;
            }
            else if(count1 == 0) {
                count1++;
                first = nums[i];
            }
            else if(count2 == 0) {
                count2++;
                second = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if(first == nums[i]) {
                count1++;
            }
            else if(second == nums[i]) {
                count2++;
            }
        }

        if(count1 > cnt) {
            ans.add(first);
        }
        if(count2 > cnt) {
            ans.add(second);
        }

        return ans;
    }

    boolean [][] vis;
    public boolean dfs(int i , int j , char[][] board , String word , int index) {
        int n = board.length;
        int m = board[0].length;
        if(check(i , j , n , m) == false) {
            return false;
        }

        if(vis[i][j] == true) return false;


        if(word.charAt(index) != board[i][j]) {
            return false;
        }
        if(index == word.length() - 1) {
            return true;
        }

        vis[i][j] = true;

        if(dfs(i + 1 , j , board , word , index + 1) ||
                dfs(i , j + 1 , board , word , index + 1) ||
                dfs(i - 1 , j , board , word , index + 1) ||
                dfs(i , j - 1 , board , word , index + 1) ) {
            return true;
        }

        vis[i][j] = false;
        return false;
    }

    private boolean check(int i, int j, int n , int m) {
        if(i >= 0 && i < n && j >= 0 && j < m) return true;
        return false;
    }

    public boolean exist(char[][] board, String word) {

        int n = board.length;
        if (n == 0) {
            if (word.equals("")) return true;
            return false;
        }

        int m = board[0].length;

        vis = new boolean[n][m];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                vis[i][j] = false;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(dfs(i , j , board , word , 0)) {
                    return true;
                }
            }
        }

        return false;
    }


    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;

        int m = costs.length;

        if(n == 0) return 0;

        int [] dp = new int[366];

        for(int i = 1 ; i < 366 ; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0] = 0;
        int didx = 0;

        for(int i = 1 ; i < 366  ; i++){

            if(didx >= days.length) break;
            if(i < days[didx]) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1] + costs[0];
                int mindp = dp[i - 1];

                for(int j = 1; j <= 7 ; j++) {
                    if(i - j < 0) {
                        break;
                    }

                    mindp = Math.min(mindp, dp[i - j]);
                }

                dp[i] = Math.min(dp[i], mindp + costs[1]);

                for(int j = 7 ; j <= 30 ; j++) {
                    if(i - j < 0) break;
                    mindp = Math.min(mindp , dp[i - j]);
                }

                dp[i] = Math.min(dp[i] , mindp + costs[2]);
                didx++;
            }
        }

        return dp[days[days.length - 1]];
    }

    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;

        if(n == 0) return 0;

        boolean[] inc = new boolean[n];
        Arrays.fill(inc , false);

        int [] dp = new int[n];
        Arrays.fill(dp , 1);

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(j == 0) {
                    if(nums[i] == nums[j]) continue;
                    dp[i] = Math.max(dp[i] , dp[j] + 1);
                    if(nums[i] > nums[j]) {
                        inc[i] = true;
                    }
                    continue;
                }
                if(nums[j] < nums[i]) {
                    if(inc[j] == false) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            inc[i] = true;
                        }

                    }
                }
                else if(nums[j] > nums[i]) {
                    if(inc[j] == true) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            inc[i] = false;
                        }
                    }
                }
            }
        }

        return dp[n - 1];
    }


    int n , m;
    public List<String> findWords(char[][] board, String[] words) {
        List < String > ans = new ArrayList<>();

        Trie t = new Trie();

        n = board.length;
        if(n == 0) {
            return ans;
        }

        m = board[0].length;
        for(String word : words) {
            t.insert(word);
        }

        boolean[][] vis = new boolean[n][m];

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                vis[i][j] = false;
            }
        }


        Set < String > res = new HashSet<>();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                String word = String.valueOf(board[i][j]);
                dfs(res , i , j , board , vis , t , word);
            }
        }

        ans.addAll(res);

        return ans;
    }
    public int[] dx = {-1, 1, 0, 0};
    public int[] dy = {0, 0, -1, 1};

    private void dfs(Set<String> res, int x, int y, char[][] board, boolean[][] vis, Trie t, String word) {
        if(x < 0 || x >= m || y < 0 || y >= m || vis[x][y]) return;

        if(t.search(word)) {
            res.add(word);
        }
        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            vis[x][y] = true;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            word = word + board[nx][ny];
            dfs(res , nx , ny , board , vis , t , word);
            vis[x][y] = false;
        }
    }


    public int movesToMakeZigzag(int[] nums) {
        int n = nums.length;

        int len = 0;
        int cnt = 0;

        if(n == 0) return 0;
        int prev = nums[0];

        for(int i = 1 ; i < n ; i++) {
            if(i % 2 == 0) {
                if(nums[i] >= prev) {
                    len += (nums[i] - prev + 1);
                    prev = prev - 1;
                }
                else {
                    prev = nums[i];
                }
            }
            else {
                if(nums[i] <= prev) {
                    len += prev - nums[i] + 1;
                    prev = nums[i];
                }
                else {
                    prev = nums[i];
                }
            }
        }

        prev = nums[0];

        for(int i = 1 ; i < n ; i++) {
            if(i % 2 != 0) {
                if(nums[i] > prev) {
                    cnt += (nums[i] - prev + 1);
                    prev = prev - 1;
                }
                else {
                    prev = nums[i];
                }
            }
            else {
                if(nums[i] <= prev) {
                    cnt += prev - nums[i] + 1;
                    prev = nums[i];
                }
                else {
                    prev = nums[i];
                }
            }
        }

        return Math.min(len , cnt);
    }

    public void setZeroes(int[][] matrix) {
        int n = matrix.length;

        if(n == 0) return ;
        int m = matrix[0].length;

        Set < pair > a = new HashSet<>();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(matrix[i][j] == 0 && !a.contains(new pair(i , j))) {
                    for(int k = 0 ; k < n ; k++) {
                        a.add(new pair(k , j));
                    }

                    for(int k = 0 ; k < m ; k++) {
                        a.add(new pair(i , k));
                    }
                }
            }
        }

        for(pair p : a) {
            matrix[(int) p.fi][(int) p.se] = 0;
        }
    }

    public static void main(String[] args) {
        int [] T = new int[4];

        Solution s = new Solution();
        char[][] board = new char[1][2];
        board[0][0] = 'a';
        board[0][1] = 'a';
        boolean flag = s.exist(board , "aa");
        System.out.println(flag);
    }

    private long modular_power(long fi, long l, long mod) {
        if(l == 0) return 1;
        long ans = modular_power(fi , l / 2 , mod);
        ans *= ans;
        ans %= mod;
        if(l % 2 != 0) {
            ans *= fi;
            ans %= mod;
        }
        return ans;
    }
    public int superPow(int a, int[] b) {
        int mod = 1337;
        int res = (int) modular_power(a , b[0] , mod);
        for(int i = 1 ; i < b.length ; i++) {
            res = (int) ((modular_power(res , 10 , mod) * modular_power(a , b[i] , mod)) % mod);
        }

        return res;
    }

}

class pair {
    public long fi;
    public long se;

    public pair(long fi, long se) {
        this.fi = fi;
        this.se = se;
    }

    public pair() {

    }

    @Override
    public int hashCode() {
        long mod = (long) (1e9 + 7);
        long ans = 0;
        ans += modular_power(fi, (long)1871 , mod);
        ans %= mod;
        ans += modular_power((long)se , (long)1871 , mod);
        ans %= mod;
        return (int) ans;
    }

    private long modular_power(long fi, long l, long mod) {
        if(l == 0) return 1;
        long ans = modular_power(fi , l / 2 , mod);
        ans *= ans;
        ans %= mod;
        if(l % 2 != 0) {
            ans *= fi;
            ans %= mod;
        }
        return ans;
    }
}