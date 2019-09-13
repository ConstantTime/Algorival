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
            if(fi != o.fi) return Integer.valueOf(Math.toIntExact((Long) fi)).compareTo(Math.toIntExact(Long.valueOf((Long) o.fi)));
            return Integer.valueOf((Integer) se).compareTo((Integer.valueOf(Math.toIntExact((Long) o.fi))));
        }
    }
}
