def initEnvironment(env):
	return env

def addExtras(context):
	context.env.Append(LIBS = 'm')
	context.env.Replace(LIBPATH = ['/opt/lib', '%s/ext/install/lib' % context.env['SCONS_ROOT_PATH']])
	context.env.Append(CPPPATH = ['/opt/include', 
	                              '/usr/include/vorbis', 
	                              '%s/ext/install/include' % context.env['SCONS_ROOT_PATH']])
	
	context.checkSimpleLib(['vorbisfile'], 'vorbisfile.h')
	context.checkSimpleLib(['openal'], 'AL/al.h')
	if context.env['script'] == 'lua':
		context.checkSimpleLib(['lua5.1', 'lua-5.1', 'lua'], 'lua.h')
	context.checkSimpleLib(['SDL'], 'SDL.h')
	context.checkSimpleLib(['SDL_ttf'], 'SDL_ttf.h')
	context.checkSimpleLib(['SDL_image'], 'SDL_image.h')
	context.checkSimpleLib(['guichan'])
	context.checkSimpleLib(['guichan_sdl'])
	context.checkSimpleLib(['boost_filesystem', 'boost_filesystem-gcc'])
	context.checkSimpleLib(['boost_regex', 'boost_regex-gcc'])
	
	if context.env['opengl']:
		context.env.Append(LIBS = ['GL', 'GLU'])
		context.env.Append(LIBPATH = ['/usr/X11R6/lib'])
		context.checkSimpleLib(['guichan_opengl'])
	
	if context.env['movie']:
		context.checkSimpleLib(['libavformat', 'avformat'], 'avformat.h')
		context.checkSimpleLib(['libavcodec', 'avcodec'], 'avcodec.h')

	if context.env['zip']:
		context.checkSimpleLib(['minizip'])