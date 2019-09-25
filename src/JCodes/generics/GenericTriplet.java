package JCodes.generics;

public class GenericTriplet {
    class pair<T, W , X> implements Comparable<GenericTriplet>{
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
        public int compareTo(GenericTriplet o) {
            return 0;
        }
    }
}
