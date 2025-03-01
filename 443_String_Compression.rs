impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let mut index = 0;
        let mut position = 0;
        while index < chars.len() {
            let curr = chars[position];
            let mut count = 0;
            while index < chars.len() && chars[index] == curr {
                count += 1; index += 1;
            }
            chars[position] = curr;
            position += 1;
            if count > 1 {
                let string = count.to_string();
                for digit in string.chars() {
                    chars[position] = digit;
                    position += 1;
                }
                for _ in string.len()..count - 1 {
                    chars.remove(position);
                    index -= 1;
                }
            }
        }
        chars.len() as i32
    }
}