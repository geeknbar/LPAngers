=begin
for i in ['hello', 'bonjour', 'guten tag']
puts i, ""
end
=end


=begin
def deux_fois
puts 'Debut'
yield
yield
puts 'Fin'
end

deux_fois { puts 'Hello' }
=end


=begin
def deux_fois
yield('appel', 1)
yield('lancement', 2)
end

deux_fois { |ch,i| puts "C est mon #{ch} numero #{i}" }
=end

=begin
p1 = Proc.new { puts 'Hello' }
p1.call

p2 = Proc.new { |x, y| x + y}
p2.call(45, 87)


=end


=begin
1.upto(15) { |x| puts x,  ' ' }

file = File.new('test.txt', 'w')
15.times { |i| file << i }
file.close
=end


ARGV.each {|arg| puts arg}