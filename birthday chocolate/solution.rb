#!/bin/ruby

def solve(n, s, d, m)

    section = s[0...m]
    sum = section.reduce(:+)
    numSolutions = (sum == d ? 1 : 0)
    (n-m).times.with_index do |index|
      sum -= section.shift
      section.push(s[m + index])
      sum += section.last
      numSolutions += 1 if sum == d
    end
    numSolutions
end

n = gets.strip.to_i
s = gets.strip
s = s.split(' ').map(&:to_i)
d, m = gets.strip.split(' ')
d = d.to_i
m = m.to_i
result = solve(n, s, d, m)
puts result;
