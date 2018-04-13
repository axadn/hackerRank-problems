#!/bin/ruby

def gridSearch(g, p)
    (0..(g.length - p.length)).any? do |outer_x|
        (0..(g[0].length - p[0].length)).any? do |outer_y|
            (0..(p.length - 1)).all? do |x_offset|
                (0..(p[0].length - 1)).all? do |y_offset|
                    g[outer_x + x_offset][outer_y + y_offset] == p[x_offset][y_offset]
                end
            end
        end
    end ? "YES" : "NO"
end

t = gets.strip.to_i
for a0 in (0..t-1)
    r, C = gets.strip.split(' ')
    r = r.to_i
    C = C.to_i
    g = Array.new(r)
    for g_i in (0..r-1)
        g[g_i] = gets.strip
    end
    r, c = gets.strip.split(' ')
    r = r.to_i
    c = c.to_i
    p = Array.new(r)
    for p_i in (0..r-1)
        p[p_i] = gets.strip
    end
    result = gridSearch(g, p)
    puts result
end
