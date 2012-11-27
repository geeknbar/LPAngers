#!/usr/bin/ruby -w

puts "quel est ton nom:"
nom = gets.strip
puts " Quelle est ton annee de naissance"
date = gets.strip.to_i
age = Time.now.year - date
puts " Salut #{nom}, cest l'annee de tes #{age} ans?"
