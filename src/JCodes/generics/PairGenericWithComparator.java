package JCodes.generics;

public class PairGenericWithComparator {
    public static class pair<T, W> implements Comparable<pair>{
        private T fi;
        private W se;

        public pair() {

        }
        public pair(T fi , W se) {
            this.fi = fi;
            this.se = se;
        }

        public T getFi() {
            return fi;
        }

        public W getSe() {
            return se;
        }

        @Override
        public int compareTo(pair o) {
            if(fi != o.fi) return Long.valueOf((Long) fi).compareTo(Long.valueOf((Long) o.fi));
            return Long.valueOf((Long) se).compareTo((Long.valueOf((Long) o.fi)));
        }
    }
}
