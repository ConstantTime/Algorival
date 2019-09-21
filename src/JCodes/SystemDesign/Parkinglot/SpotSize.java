package JCodes.SystemDesign.Parkinglot;

public enum SpotSize {

    SMALL(1), MEDIUM(2), LARGE(3);

    private int size;

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    SpotSize(int i) {
        this.size = size;
    }
}
