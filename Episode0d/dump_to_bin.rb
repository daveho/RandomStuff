#! /usr/bin/env ruby

# Convert the output of the Dump_M48T59Y sketch to a binary file.

raise "Usage: ./dump_to_bin.rb <dump file> <output file>" unless ARGV.length == 2

dump_file = ARGV[0]
output_file = ARGV[1]

File.open( dump_file ) do |inf|
  File.open( output_file, 'wb' ) do |outf|
    inf.each_line do |line|
      line.scan( /0x[0-9A-Fa-f]+/ ) do |hex|
        byte = hex.to_i( 16 )
        outf.write( [byte].pack('C') )
      end
    end
  end
end
