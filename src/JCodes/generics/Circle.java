package JCodes.generics;

public class Circle extends Shape {
    @Override
    public void draw() {
        super.draw();
        System.out.println("Rakshit");
    }

    public static void main(String[] args) {
        Circle s = new Circle();
        s.draw();
    }

}
