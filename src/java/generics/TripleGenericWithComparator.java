package java.generics;

public class TripleGenericWithComparator {
    class pair<T, W , X> implements Comparable<TripleGenericWithComparator>{
        private T fi;
        private W se;
        private X th;

        public pair() {

        }
        public pair(T fi , W se, X th) {
            this.fi = fi;
            this.th = th;
            this.se = se;
        }

        public T getFi() {
            return fi;
        }

        public W getSe() {
            return se;
        }

        public X getTh () {
            return th;
        }

        @Override
        public int compareTo(TripleGenericWithComparator o) {
            return 0;
        }
    }
}
