const ffi = require('ffi-napi');
const ref = require('ref-napi');

const lib = ffi.Library('./bot', {
	'handleCommand': [ 'CString', ['CString', 'CString', 'CString', 'CString']]
});

const MPPClient = require('mppclone-client');
const cl = new MPPClient('wss://mppclone.com:8443', undefined);
cl.start();
cl.setChannel('✧𝓓𝓔𝓥 𝓡𝓸𝓸𝓶✧');

cl.on('a', msg => {
	if (msg.p._id == cl.getOwnParticipant()._id) return;
	let out = lib.handleCommand(msg.p._id, msg.p.name, msg.p.color, msg.a);

	if (out) {
		cl.sendArray([{m: 'a', message: out}]);
	}
});
