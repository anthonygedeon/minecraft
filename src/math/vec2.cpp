#include <cmath>
#include <strstream>

namespace math {

	class Vec2 {
	public:
		int x{}, y{};

		Vec2(int x, int y) : x{x}, y{y} {}

		~Vec2() = default;

		inline static Vec2 zero() {
			return { 0, 0 };
		}

		inline static Vec2 one() {
			return { 1, 1 };
		}

		inline double length() const {
			return std::sqrt(x * x + y * y);
		}

		// TODO
		Vec2 normalized() const {

		}
		
		// TODO
		void normalize() {

		}

		// TODO
		int dot() const {

		}

		// TODO
		int cross() const {

		}

		// TODO
		double distance() const {

		}

		// TODO
		double angle() const {

		}

		// TODO
		Vec2 clamped(const Vec2& min, const Vec2& max) const {

		}

		// TODO
		Vec2 lerp(const Vec2& target, double t) {
			 // percentage = clamped(percentage);

			// Calculate the mid-point between start and end
			// Multiply the result with the percentage
			// The result will be added back to start so we can get the point that is in between the line
			// return start + (end - start) * percentage
		}

		friend Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
			return { lhs.x + rhs.x, lhs.y + rhs.y };
		}

		// TODO
		friend Vec2 operator+=(const Vec2& lhs, const Vec2& rhs) {
			return { lhs.x + rhs.x, lhs.y + rhs.y };
		}

		friend Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
			return { lhs.x - rhs.x, lhs.y - rhs.y };
		}

		// TODO
		friend Vec2 operator-=(const Vec2& lhs, const Vec2& rhs) {
			return { lhs.x - rhs.x, lhs.y - rhs.y };
		}

		friend Vec2 operator*(const Vec2& lhs, int scale) {
			return { lhs.x * scale, lhs.y * scale };
		}

		// TODO
		friend Vec2 operator*=(const Vec2& lhs, int scale) {
			return { lhs.x * scale, lhs.y * scale };
		}

		friend Vec2 operator/(const Vec2& lhs, int scale) {
			return { lhs.x / scale, lhs.y / scale };
		}

		// TODO
		friend Vec2 operator/=(const Vec2& lhs, int scale) {
			return { lhs.x / scale, lhs.y / scale };
		}

		friend std::ostream& operator<< (std::ostream& out, const Vec2& v) {
			return out << "Vec(" << v.x << ", " << v.y << ")";
		}
	private:
	};

}

