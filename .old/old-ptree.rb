
FILE = Struct.new :name, :link, :is_dir


def tree path
	lines = []
	files = []
	dirs = []
	
	(Dir.entries path).each do |file|
		next if [".", ".."].include? file
		path_to_file = path + ?/ + file
		
		link = File.readlink path_to_file rescue nil
		
		if File.directory? path_to_file
			dirs << (FILE.new file, link, true)
		else
			files << (FILE.new file, link, false)
		end
	end
	
	files = (dirs.sort_by &:name) + (files.sort_by &:name)
	
	files.each.with_index do |file, i|
		lines << (i < files.length - 1 ? "├── " : "└── ")
		
		if file.is_dir
			if file.link
				lines [-1] += "%s ~> \e[91m%s/\e[0m" % [file.name, file.link]
			else
				lines [-1] += "\e[91m%s/\e[0m" % file.name
				lines += (tree path + ?/ + file.name).map do |line|
					(i < files.length - 1 ? "│   " : "    ") + line
				end
			end
		else
			if file.link
				lines [-1] += file.name + " ~> " + file.link
			else
				lines [-1] += file.name
			end
		end
	end
	
	lines
end


file = File.basename (ARGV.first || ".")

puts "\e[91m%s/\e[0m" % (file == "." ? (File.basename Dir.getwd) : file)
puts tree file





